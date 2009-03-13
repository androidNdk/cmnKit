#include "Common/Common.h"

#include "TCPConnection.h"

#include "Service.h"

#include "HandlerWrapper.h"

namespace MinCOM
{

	TCPConnection::TCPConnection(IServiceRef service)
		: mc::CommonImpl< IConnection >()
		, mc::APImpl()
		, service_( service )
		, socket_( new Socket_( Strong< Service >(service_)->GetService() ) )
		, ibuffer_()
		, obuffer_()
		, events_()
	{
	}

	TCPConnection::TCPConnection(IServiceRef service, const SocketPtr_& socket)
		: mc::CommonImpl< IConnection >()
		, mc::APImpl()
		, service_( service )
		, socket_( socket )
		, ibuffer_()
		, obuffer_()
		, events_()
	{
	}

	TCPConnection::~TCPConnection()
	{
		socket_->close();
	}

	// ITCPConnection section
	//////////////////////////////////////////////////////////////////////////

	result TCPConnection::Establish(const std::string& host, const std::string& service)
	{
        MC_LOG_ROUTINE;
		CoreMutexLock locker(CommonImpl< IConnection >::GetLock());

		try
		{
			// Flush buffers.
			ibuffer_.consume(ibuffer_.size());
			obuffer_.consume(obuffer_.size());

			// Establish new one.
			boost::asio::ip::tcp::resolver resolver(Strong< Service >(service_)->GetService());
			boost::asio::ip::tcp::resolver::query query(host, service);
			boost::asio::ip::tcp::resolver::iterator endpointIterator = resolver.resolve(query);
			boost::asio::ip::tcp::resolver::iterator end;

			// Try each endpoint until we successfully establish a connection.
			boost::system::error_code error = boost::asio::error::host_not_found;
			while ( error && endpointIterator != end )
			{
				socket_->close();
				socket_->connect(*endpointIterator++, error);
			}

			if ( error )
				return mc::_E_FAIL;

			// Spread good news.
			events_->Connected( CommonImpl< IConnection >::GetSelf() );

			// Make this object immortal.
			self_ = CommonImpl< IConnection >::GetSelf();
		}
		catch( ... )
		{
			return mc::_E_FAIL;
		}

		return mc::_S_OK;
	}

	result TCPConnection::Establish(IHostRef host)
	{
		return Establish(host->GetHost(), host->GetService());
	}

	std::string TCPConnection::GetIpAddress()
	{
		return socket_->remote_endpoint().address().to_string();
	}

	void TCPConnection::ReadAsync(std::size_t minimum)
	{
		MC_LOG_ROUTINE;
		boost::asio::async_read(
			*socket_, 
			ibuffer_, 
			boost::asio::transfer_at_least(minimum),
			boost::bind(
                &TCPConnection::HandleRead, 
                // This workaround helps to maintain lifetime of this (TCPConnection) object independently 
                // from client application architecture.
                HandlerWrapper< TCPConnection >::Ptr_( new HandlerWrapper< TCPConnection >(this, CommonImpl< IConnection >::GetSelf()) ),
                boost::asio::placeholders::error));
	}

	void TCPConnection::WriteAsync()
	{
		MC_LOG_ROUTINE;
		boost::asio::async_write(
			*socket_, 
			obuffer_,
			boost::asio::transfer_all(),            
			boost::bind(
                &TCPConnection::HandleWrite, 
                // This workaround helps to maintain lifetime of this (TCPConnection) object independently 
                // from client application architecture.
                // ConnectionHolder_::Ptr_(new ConnectionHolder_(this, CommonImpl< IConnection >::GetSelf())),
                HandlerWrapper< TCPConnection >::Ptr_( new HandlerWrapper< TCPConnection >(this, CommonImpl< IConnection >::GetSelf()) ),
                boost::asio::placeholders::error));
	}

	std::streambuf& TCPConnection::GetIStreamBuf()
	{
		return ibuffer_;
	}

	size_t TCPConnection::GetISize()
	{
		return ibuffer_.size();
	}

	std::streambuf& TCPConnection::GetOStreamBuf()
	{
		return obuffer_;
	}

	size_t TCPConnection::GetOSize()
	{
		return obuffer_.size();
	}

	// ICommon section
	//////////////////////////////////////////////////////////////////////////

	result TCPConnection::PostInit()
	{
		// Register additional access point for events' delivery and configure 
		// events spreader.
		events_ = APImpl::AdviseAndThrow( TypeInfo< DRawData >::GetGuid() );
		return _S_OK;
	}

	// Async handlers
	//////////////////////////////////////////////////////////////////////////
	void TCPConnection::HandleWrite(const boost::system::error_code& error)
	{
		if ( !HandleError(error) )
		{
			// Error was detected, handled and dispatched. Required cleanup 
			// was also performed. So.. nothing else should be done here.
			return;
		}
	}

	void TCPConnection::HandleRead(const boost::system::error_code& error)
	{
		if ( !HandleError(error) )
		{
			// Error was detected, handled and dispatched. Required cleanup 
			// was also performed. So.. nothing else should be done here.
			return;
		}
		
		// Spread event to subscribers.
		events_->DataReceived( CommonImpl< IConnection >::GetSelf() );		
        
		// Continue asynchronous reading.
        ReadAsync();        
	}

	// Internal helpers
	//////////////////////////////////////////////////////////////////////////

	bool TCPConnection::HandleError(const boost::system::error_code& error)
	{
		MC_LOG_ROUTINE;
		CoreMutexLock locker(CommonImpl< IConnection >::GetLock());
		MC_LOG_STATEMENT("Unlocked");

		if ( error )
		{
			MC_LOG_ROUTINE_NAMED("Disconnecting");
			// Connection closed cleanly by peer.
			events_->Disconnected( CommonImpl< IConnection >::GetSelf() );
			return false;
		}

		return true;
	}

}

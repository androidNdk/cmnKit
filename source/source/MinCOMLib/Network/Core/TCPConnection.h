#ifndef TCPCONNECTION_H__MINCOMLIB__INCLUDED_
#define TCPCONNECTION_H__MINCOMLIB__INCLUDED_

namespace MinCOM
{

	class TCPConnection
		: public CommonImpl< IConnection >
		, public APImpl
	{
    public:

		typedef CommonImpl< IConnection > ClassRoot_;

		/**
	 	 * Typedef for socket entity to be used by classes from TCP family.
		 */ 
		typedef boost::asio::ip::tcp::socket Socket_;

		/**
		 * Pointer wrapping TCP socket.
		 */ 
		typedef boost::shared_ptr< Socket_ > SocketPtr_;

    public:

		TCPConnection(IServiceRef service);

		TCPConnection(IServiceRef service, const SocketPtr_& socket);

		virtual ~TCPConnection();

		// ITCPConnection section
		//////////////////////////////////////////////////////////////////////////

		virtual result Establish(const std::string& host, const std::string& service);

		virtual result Establish(IHostRef host);
        
        virtual result Close();        
		
		virtual IServicePtr GetService() const;		

		virtual State_ GetState();

		virtual std::string GetIpAddress();

		virtual void ReadAsync(std::size_t minimum = 1);

		virtual void WriteAsync();
        
		virtual void Write();        

		virtual std::streambuf& GetIStreamBuf();

		virtual size_t GetISize();

		virtual std::streambuf& GetOStreamBuf();

		virtual size_t GetOSize();

		// ICommon section
		//////////////////////////////////////////////////////////////////////////

		/**
		 * Overridden to init events spreader.
		 */
		virtual result PostInit();

	private:

		/**
		 * This callback is passed to ASIO internals and is called 
		 * when data is sent.
		 */ 
		void HandleWrite(const boost::system::error_code& error);

		/**
		 * This callback is passed to ASIO internals and is called 
		 * when data is arrived.
		 */ 
		void HandleRead(const boost::system::error_code& error);

	protected:

		/**
		 * Handles error correctly. 
		 * Performs required cleanup of the TCPConnection entry and
		 * dispatches corresponding events to subscribers.
		 *
		 * @return Returns false if an error has occurred.
		 */
		bool HandleError(const boost::system::error_code& error);

		/** 
		 * Notifies all subscribers on disconnection from io_service pool.
		 */
		void HandleDisconnectionInIOServiceThread();

		/** 
		 * Notifies all subscribers on disconnection and performs required 
		 * cleanup.
		 */
		void HandleDisconnection();
        
	private:
        
		/** Service responsible for I/O networking operations. */
		IServicePtr service_;

		/** TCP socket. */
		SocketPtr_ socket_;

		/** Connection state. */
		State_ state_;

		/** Buffer to hold received data. */
		boost::asio::streambuf ibuffer_;

		/** Buffer to hold data to be sent. */
		boost::asio::streambuf obuffer_;
        
		/** Connection events spreader. */
		DRawDataPtr events_;

	};
    
}

#endif // !TCPCONNECTION_H__MINCOMLIB__INCLUDED_

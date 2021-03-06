#ifndef SEMAPHORE_H__MINCOMLIB__INCLUDED_
#define SEMAPHORE_H__MINCOMLIB__INCLUDED_

namespace MinCOM
{

	class Semaphore 
		: public CommonImpl< ISemaphore >
	{
	public:

		Semaphore(long initial, long maximum, const std::string& name);
		
		Semaphore(const std::string& name);
		
		virtual ~Semaphore();

		// ISemaphore section
		virtual result Release(long count = 1);

		// ISynchro section
		virtual result Wait(unsigned long delay = _INFINITE);

		virtual result Close();

	private:
		
#if defined(WIN32)
		/** Handle for win32 environments. */
		HANDLE semaphore_;
#elif defined(POSIX)
		/** Handle for posix environments. */
		sem_t *semaphore_;
#endif
		
	};

}

#endif // !SEMAPHORE_H__MINCOMLIB__INCLUDED_

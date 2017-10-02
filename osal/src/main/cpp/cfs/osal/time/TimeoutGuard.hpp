
#ifndef CFS_OSAL_TIME_TIMEOUTGUARD_HPP
#define CFS_OSAL_TIME_TIMEOUTGUARD_HPP

#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

class TimeoutGuard 
{
    using clock = std::chrono::system_clock;
public:
    TimeoutGuard();
    TimeoutGuard( const TimeoutGuard & ) = delete;
    TimeoutGuard & operator = (const TimeoutGuard & ) = delete;
    TimeoutGuard( TimeoutGuard && ) = delete;
    TimeoutGuard & operator = ( TimeoutGuard && ) = delete;
    virtual ~TimeoutGuard() = default;
    
    TimeoutGuard(clock::duration timeout ,
                 std::function<void ( void )> alarm ,
                 clock::duration naptime );
    TimeoutGuard(clock::duration timeout ,
                 std::function<void ( void )> alarm);
private:

    void guard ();

    clock::duration m_timeout;
    clock::duration m_naptime;
    
    std::function<void ( void )> m_alarm;

    std::atomic_bool m_idle;
    std::atomic_bool m_live;

    std::atomic<clock::time_point> m_touched;

    std::thread m_guard_thread;
    std::mutex m_guard_mutex;
    std::condition_variable m_wakeup;
};

#endif


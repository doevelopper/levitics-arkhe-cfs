#ifndef CFS_OSAL_TIME_TIMESPAN_HPP
#define CFS_OSAL_TIME_TIMESPAN_HPP

#include <cstdint>
#include <time.h>
#include <iosfwd>

namespace cfs
{
    namespace osal
    {
        namespace time
        {

            enum class Clock : int 
            {
		
		REALTIME    = CLOCK_REALTIME,              /// System-wide realtime clock. Setting this clock requires appropriate privileges.
		MONOTONIC   = CLOCK_MONOTONIC,            /// Clock that cannot be set and represents monotonic time since some unspecified starting point.
		PROCESS     = CLOCK_PROCESS_CPUTIME_ID,     /// High-resolution per-process timer from the CPU.
		THREAD      = CLOCK_THREAD_CPUTIME_ID,       /// Thread-specific CPU-time clock.
            };

            class TimeSpan 
            {
            public:
                using times = struct timespec;
                static constexpr std::int64_t NS = 1000*1000*1000;
                static constexpr std::int64_t MS = 1000;

                TimeSpan();
                TimeSpan(const times & value) noexcept; 
		TimeSpan(int seconds) noexcept;
                TimeSpan(double seconds) noexcept;
                virtual ~TimeSpan() = default;
                TimeSpan(const Clock & clock = Clock::MONOTONIC) noexcept;
                
                const times & getTimespec() const noexcept;
                std::int64_t milliseconds() const noexcept;
                double seconds() const noexcept;
                operator double() const noexcept
                {
                    return seconds();
                }

		TimeSpan operator-() const noexcept
		{
			return TimeSpan({this->m_value.tv_sec * -1, this->m_value.tv_nsec});
                }

                TimeSpan operator-(const TimeSpan & rhs) const noexcept
                {
                    auto & a = this->m_value;
                    auto & b = rhs.m_value;
                    auto seconds = a.tv_sec - b.tv_sec;
                    auto nanoseconds = a.tv_nsec - b.tv_nsec;

                    if (nanoseconds < 0) 
                    {
			seconds -= 1;
			nanoseconds += NS;
                    }
			
                    return times{seconds, nanoseconds};
                }

		TimeSpan & operator-=(const TimeSpan & rsh) noexcept
		{
			return ((*this) = (*this) - rsh);
                }
                
                TimeSpan operator+(const TimeSpan & rhs) const noexcept
                {
                    auto & a = this->m_value;
                    auto & b = rhs.m_value;
                    auto seconds = a.tv_sec - b.tv_sec;
                    auto nanoseconds = a.tv_nsec - b.tv_nsec;

                    if (nanoseconds > NS) 
                    {
                    	seconds += 1;
                    	nanoseconds -= NS;
                    }
			
                    return times{seconds, nanoseconds};
                }

		TimeSpan & operator+=(const TimeSpan & rsh) noexcept
		{
			return ((*this) = (*this) + rsh);
                }

		bool operator==(const TimeSpan & other) const noexcept
		{
			auto & a = this->m_value;
			auto & b = other.m_value;
			
			return (a.tv_sec == b.tv_sec && a.tv_nsec == b.tv_nsec);
		}
		
		bool operator!=(const TimeSpan & other) const noexcept
		{
			auto & a = this->m_value;
			auto & b = other.m_value;
			
			return (a.tv_sec != b.tv_sec || a.tv_nsec != b.tv_nsec);
		}
		
		bool operator<(const TimeSpan & other) const noexcept
		{
                    auto & a = this->m_value;
                    auto & b = other.m_value;
			
                    if (a.tv_sec < b.tv_sec) 
                    {
			return true;
                    } 
                    else if (a.tv_sec == b.tv_sec && a.tv_nsec < b.tv_nsec) 
                    {
                        return true;
                    } 
                    else 
                    {
			return false;
                    }
		}
		
		bool operator<=(const TimeSpan & other) const noexcept
		{
                    auto & a = this->m_value;
                    auto & b = other.m_value;
			
                    if (a.tv_sec < b.tv_sec) 
                    {
			return true;
                    } 
                    else if (a.tv_sec == b.tv_sec && a.tv_nsec <= b.tv_nsec) 
                    {
			return true;
                    } 
                    else 
                    {
			return false;
                    }
		}
		
		bool operator>(const TimeSpan & other) const noexcept
		{
                    auto & a = this->m_value;
                    auto & b = other.m_value;
			
                    if (a.tv_sec > b.tv_sec) 
                    {
                    	return true;
                    } 
                    else if (a.tv_sec == b.tv_sec && a.tv_nsec > b.tv_nsec) 
                    {
			return true;
                    } 
                    else 
                    {
			return false;
                    }
		}
		
		bool operator>=(const TimeSpan & other) const noexcept
		{
                    auto & a = this->m_value;
                    auto & b = other.m_value;
			
                    if (a.tv_sec > b.tv_sec) 
                    {
			return true;
                    } 
                    else if (a.tv_sec == b.tv_sec && a.tv_nsec >= b.tv_nsec) 
                    {
			return true;
                    } 
                    else 
                    {
			return false;
                    }
                }
            private:
                times m_value = {0, 0};
            };
        std::ostream & operator<<(std::ostream & out, const TimeSpan & timeSpan);
        }
    }
}



#endif


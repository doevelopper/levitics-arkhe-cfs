#include <cfs/osal/time/TimeSpan.hpp>

using namespace cfs::osal::time;

//constexpr std::int64_t TimeSpan::NS = 1000*1000*1000;
//constexpr std::int64_t TimeSpan::MS = 1000;
                
TimeSpan::TimeSpan() 
{
}

TimeSpan::TimeSpan(const times & value) noexcept
: m_value(value)
{

}

TimeSpan::TimeSpan(int seconds) noexcept 
: TimeSpan({seconds, 0}) 
{
}

TimeSpan::TimeSpan(double seconds) noexcept
{
    
}

TimeSpan::TimeSpan(const Clock & clock) noexcept
{
    //clock_gettime((clockid_t)clock, &this->m_value);
    clock_gettime(static_cast<clockid_t>(clock), &this->m_value);
}

const TimeSpan::times & 
TimeSpan::getTimespec( ) const noexcept 
{
    return (this->m_value);
}

std::int64_t 
TimeSpan::milliseconds() const noexcept 
{
    return (this->m_value.tv_sec*MS + this->m_value.tv_nsec/(NS/MS));
}

double TimeSpan::seconds() const noexcept 
{   
    return (static_cast<double>(this->m_value.tv_sec) + static_cast<double>(this->m_value.tv_nsec) / NS);
}

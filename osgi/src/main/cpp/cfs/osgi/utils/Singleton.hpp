#ifndef CFS_OSGI_UTILS_SINGLETON_HPP
#define CFS_OSGI_UTILS_SINGLETON_HPP

#include <memory>
#include <mutex>

class Singleton 
{
public:

    virtual ~Singleton() = default;
    
    static Singleton& instance();



private:
    Singleton() = default;
    Singleton(const Singleton& src) = delete;
    Singleton& operator=(const Singleton& rhs) = delete;
    
    static std::unique_ptr<Singleton> m_instance;
    static std::once_flag m_onceFlag;
};

#endif


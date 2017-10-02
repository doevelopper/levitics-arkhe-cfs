#ifndef CFS_OSGI_UTILS_SINGLETON_HPP
#define CFS_OSGI_UTILS_SINGLETON_HPP

#include <memory>
#include <mutex>

//template<class T>
class Singleton final
{
public:

    static Singleton& instance(); //c++11
    static Singleton& getInstance(); //c++14 guarantees that this will be initialized in a thread-safe way

private:
    Singleton() = default;
    virtual ~Singleton() = default;
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;
    
    static std::unique_ptr<Singleton> m_instance;
//    static static T* m_instance;
    static std::once_flag m_onceFlag;
};

#endif


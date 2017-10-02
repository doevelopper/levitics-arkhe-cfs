

#include <cfs/osgi/utils/Singleton.hpp>

std::unique_ptr<Singleton> Singleton::m_instance;
std::once_flag Singleton::m_onceFlag;
 
Singleton& Singleton::instance()
{
    std::call_once(m_onceFlag,
        [] {
            m_instance.reset(new Singleton);
    });
    return *m_instance.get();
}

& Singleton::getInstance()
{
    static Singleton instance;
    return instance;
}

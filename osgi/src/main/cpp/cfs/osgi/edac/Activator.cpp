
#include <cfs/osgi/edac/Activator.hpp>

template <class T>
cfs::osgi::edac::Activator<T>::Activator() 
    : m_value(T())
    , m_isValid(false)
{
}

template <class T>
cfs::osgi::edac::Activator<T>::~Activator() 
{
}

template <class T>
void cfs::osgi::edac::Activator<T>::value (const T &value)
{
    this->m_value = value;
    this->m_isValid = true;
}

template <class T>
T cfs::osgi::edac::Activator<T>::value () const
{
    return (this->m_value);
}

template <class T>
const bool cfs::osgi::edac::Activator<T>::isValid () const
{
    return (this->m_isValid);
}

template <class T>
void cfs::osgi::edac::Activator<T>::isValid (bool value)
{
    this->m_isValid = value;
}

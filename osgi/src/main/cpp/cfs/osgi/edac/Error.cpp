#include <cfs/osgi/edac/Error.hpp>

//
//Error::Error() 
//{
//}

const char* 
cfs::osgi::edac::Error::what() const throw()
{
    return (m_message.c_str());
}

const char* 
cfs::osgi::edac::Error::where() const throw()
{
    return(m_location.c_str());
}


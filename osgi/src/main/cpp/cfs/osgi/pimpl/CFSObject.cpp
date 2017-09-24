#include <cfs/osgi/pimpl/CFSObject.hpp>

using namespace cfs::osgi::pimpl;

CFSObject::None::None()
{

}

CFSObject::None::~None()
{

}

CFSObject::CFSObject() 
:m_none(nullptr)
{
}

template < class T >
CFSObject::Data<T>::Data()
{

}

CFSObject::~CFSObject() 
{
    if (!empty())
    {
        delete m_none;
    }
}

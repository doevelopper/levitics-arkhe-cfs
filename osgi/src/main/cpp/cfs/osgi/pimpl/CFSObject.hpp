#ifndef CFS_OSGI_PIMPL_CFSOBJECT_HPP
#define CFS_OSGI_PIMPL_CFSOBJECT_HPP

#include <utility>
#include <typeinfo>

namespace cfs
{
    namespace osgi
    {
        namespace pimpl
        {
            class CFSObject 
            {
                class None
                {
                public:

                    None();
                    virtual ~None();
                    virtual const std::type_info &type () = 0;
                    virtual None * duplicate () const = 0;
                    virtual bool eq (CFSObject &) = 0;
                };

                template < class T >
                class Data : public None
                {
                public:
                    Data();
                    virtual ~Data();
                    Data(const T & value);
                    const std::type_info &type ();
                    Data * duplicate () const;
                    bool eq (CFSObject &Obj);
                    T var;
                };

            public:
                CFSObject();
                virtual ~CFSObject();
                template < typename T >
                CFSObject(const T & value);
                CFSObject(const CFSObject & Obj);
                const std::type_info &type ();

                CFSObject &operator = (CFSObject &rhs)
                {
                    m_none = rhs.m_none->duplicate();
                    return *this;
                }

                CFSObject &swap (CFSObject &rhs)
                {
                    std::swap(*this , rhs);
                    return *this;
                }

                template<class T> 
                bool isType()
                {
                    return (dynamic_cast<T*>(this) ? true : false); 
                }

                template < typename T >
                CFSObject &operator = (const T & value)
                {
                    if (this != &value)
                    {
                        m_none = new Data<T>(value);
                    }

                    return *this;
                }

                //    CFSObject &operator=(CFSObject & rhs)
                //    {
                //       // none = rhs.none->duplicate();
                //        return *this;
                //    }

                template < typename T >
                T cast ()
                {
                    if (type() == typeid(T))
                    {
                        return static_cast<Data<T> *>(m_none)->type;
                    }

                    // throw std::exception("Invalid cast type");
                }

                bool operator == (CFSObject & rhs)
                {
                    return (type() == rhs.m_none->type() ? m_none->eq(rhs) : false);
                }

                template < typename T >
                bool operator == (T value)
                {
                    return (type() == typeid(T) ? cast<T>() == value : false);
                }

                bool operator != (CFSObject & rhs)
                {
                    return !(*this == rhs);
                }

                template < typename T >
                bool operator != (const T & value)
                {
                    return !(*this == value);
                }

                bool empty ();

            private:
                None * m_none;
            };
        }    
    }
}    
#endif


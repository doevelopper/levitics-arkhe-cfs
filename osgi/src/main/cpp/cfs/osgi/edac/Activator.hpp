
#ifndef CFS_OSGI_EDAC_ACTIVATOR_HPP
#define CFS_OSGI_EDAC_ACTIVATOR_HPP

namespace cfs
{
    namespace osgi
    {
        namespace edac
        {
         
            //Activator<insigned int> vUint;
            template <class T>
            class Activator 
            {
            public:
                Activator();
                virtual ~Activator();
                
                [[noreturn]] void value (const T &value);
                T value () const;
                const bool isValid () const;
                [[noreturn]] void isValid (bool value);
            private:
                T    m_value;
                bool m_isValid;
            };
        }
    }
}

#endif


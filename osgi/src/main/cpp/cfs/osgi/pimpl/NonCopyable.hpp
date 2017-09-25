
#ifndef CFS_OSGI_PIMPL_NONCOPYABLE_HPP
#define CFS_OSGI_PIMPL_NONCOPYABLE_HPP

class NonCopyable
{
    public:

        NonCopyable();
        virtual ~NonCopyable() = default;

    private:

        NonCopyable( const NonCopyable & ) = delete;
        void
        operator = ( const NonCopyable & ) = delete;
};

#endif

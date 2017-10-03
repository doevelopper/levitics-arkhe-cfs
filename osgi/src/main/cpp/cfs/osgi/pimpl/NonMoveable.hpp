
#ifndef CFS_OSGI_PIMPL_NONMOVEABLE_HPP
#define CFS_OSGI_PIMPL_NONMOVEABLE_HPP
#include <cfs/osgi/pimpl/NonCopyable.hpp>
class NonMoveable
{
    public:

        NonMoveable();
        virtual ~NonMoveable() = default;

    private:

        NonMoveable( NonMoveable && ) = delete;
// void operator = (NonMoveable &&) = delete;
        void operator = ( NonCopyable && ) = delete;
};

#endif

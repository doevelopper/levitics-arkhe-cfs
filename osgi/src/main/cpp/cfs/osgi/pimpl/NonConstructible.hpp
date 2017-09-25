
#ifndef CFS_OSGI_PIMPL_NONCONSTRUCTIBLE_HPP
#define CFS_OSGI_PIMPL_NONCONSTRUCTIBLE_HPP

#include <cfs/osgi/pimpl/NonCopyable.hpp>
#include <cfs/osgi/pimpl/NonMoveable.hpp>

class NonConstructible :
                       NonCopyable, NonMoveable
{
    public:

        virtual ~NonConstructible() = default;

    private:

        NonConstructible() = delete;
};

#endif

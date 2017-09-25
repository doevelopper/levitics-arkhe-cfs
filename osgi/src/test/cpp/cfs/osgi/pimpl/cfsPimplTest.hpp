
#ifndef CFS_OSGI_PIMPL_CFSPIMPLTEST_HPP
#define CFS_OSGI_PIMPL_CFSPIMPLTEST_HPP

#include <cfs/osgi/pimpl/cfsPimpl.hpp>
#include <gmock/gmock.h>

class cfsPimplTest :
                   public ::testing::Test
{
    public:

        cfsPimplTest();
        virtual ~cfsPimplTest() = default;

        virtual void
        SetUp ();
        virtual void
        TearDown ();

    private:

// cfs::osgi::file::File * m_objectUnderTest;
};

#endif

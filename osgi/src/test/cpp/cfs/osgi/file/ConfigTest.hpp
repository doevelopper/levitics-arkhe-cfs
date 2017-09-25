
#ifndef CFS_OSGI_FILE_CONFIGTEST_HPP
#define CFS_OSGI_FILE_CONFIGTEST_HPP
#include <gmock/gmock.h>
#include <cfs/osgi/file/Config.hpp>

class ConfigTest :
                 public ::testing::Test
{
    public:

        ConfigTest();
        virtual ~ConfigTest() = default;

        virtual void
        SetUp ();
        virtual void
        TearDown ();

    private:

        cfs::osgi::file::Config * m_objectUnderTest;
};

#endif

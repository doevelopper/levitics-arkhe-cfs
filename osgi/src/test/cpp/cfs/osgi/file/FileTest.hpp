
#ifndef CFS_OSGI_FILE_FILETEST_HPP
#define CFS_OSGI_FILE_FILETEST_HPP

#include <cfs/osgi/file/File.hpp>
#include <gmock/gmock.h>

class FileTest :
               public ::testing::Test
{
    public:

        FileTest();
        virtual ~FileTest() = default;

        virtual void
        SetUp ();
        virtual void
        TearDown ();

        void
        testopenFile ();

    private:

        cfs::osgi::file::File * m_objectUnderTest;
};

#endif

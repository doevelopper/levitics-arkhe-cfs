#include <cfs/osgi/file/FileTest.hpp>

FileTest::FileTest()
:m_objectUnderTest(nullptr)
{
}

void FileTest::SetUp ()
{
    m_objectUnderTest = new cfs::osgi::file::File();
}

void FileTest::TearDown ()
{
    delete m_objectUnderTest;
}


TEST_F(FileTest , testopenFile)
{
    
}
#include <cfs/osgi/file/ConfigTest.hpp>

ConfigTest::ConfigTest() 
:m_objectUnderTest(nullptr)
{
}

void ConfigTest::SetUp ()
{
    m_objectUnderTest = new cfs::osgi::file::Config();
}

void ConfigTest::TearDown ()
{
    delete m_objectUnderTest;
}

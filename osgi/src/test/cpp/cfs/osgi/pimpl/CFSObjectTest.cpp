
#include <cfs/osgi/pimpl/CFSObjectTest.hpp>

CFSObjectTest::CFSObjectTest()
    : m_objectUnderTest( nullptr )
{
}

void CFSObjectTest::SetUp ()
{
// m_objectUnderTest = new cfs::osgi::pimpl::CFSObject();
}

void CFSObjectTest::TearDown ()
{
    delete m_objectUnderTest;
}

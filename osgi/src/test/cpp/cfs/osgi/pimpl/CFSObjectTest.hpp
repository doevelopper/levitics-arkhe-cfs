

#ifndef CFS_OSGI_PIMPL_CFSOBJECTTEST_HPP
#define CFS_OSGI_PIMPL_CFSOBJECTTEST_HPP

#include <cfs/osgi/pimpl/CFSObject.hpp>
#include <gmock/gmock.h>

class CFSObjectTest : public ::testing::Test
{
public:
    CFSObjectTest();
    virtual ~CFSObjectTest() = default;
    
    virtual void SetUp ();
    virtual void TearDown ();

private:

    cfs::osgi::pimpl::CFSObject * m_objectUnderTest;
};

#endif


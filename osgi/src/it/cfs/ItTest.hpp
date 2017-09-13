
#ifndef CFS_OSGI_ITTEST_HPP
#define CFS_OSGI_ITTEST_HPP

#include <gtest/gtest.h>
#include <cucumber-cpp/autodetect.hpp>

using cucumber::ScenarioScope;

class ItTest 
{
public:
    ItTest();
    ItTest(int argc, char* argv[]);
    virtual ~ItTest() = default;
private:

};

#endif


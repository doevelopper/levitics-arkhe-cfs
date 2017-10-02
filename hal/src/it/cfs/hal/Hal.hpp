
#ifndef CFS_HAL_HPP
#define CFS_HAL_HPP
#include <memory>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cucumber-cpp/autodetect.hpp>

#include <cfs/hal/SystemInfo.hpp>

using cucumber::ScenarioScope;

class Hal 
{
    public:

        Hal();
        virtual ~Hal() = default;

    private:
};

GIVEN("^a mock HW with method getDeviceId$") {
    ScenarioScope<Hal> context{};
//    context->mock = std::make_shared<Mock_Foo>();
}

GIVEN("^the tests expects that getDeviceId is called once$") {
    ScenarioScope<Hal> context{};
//	EXPECT_CALL(*context->mock, foo());
}

WHEN("^getDeviceId is called on the mock$") {
    ScenarioScope<Hal> context{};
//	context->mock->foo();
}

THEN("^the test should pass$") {
    ScenarioScope<Hal> context{};
//	ASSERT_TRUE(::testing::Mock::VerifyAndClearExpectations(context->mock.get()));
}

#endif


#ifndef CFS_HAL_SYSTEMINFOTEST_HPP
#define CFS_HAL_SYSTEMINFOTEST_HPP
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <benchmark/benchmark_api.h>

// #include <cfs/hal/SystemInfo.hpp>

class SystemInfoTest :
                     public ::testing::Test
{
    public:

        SystemInfoTest();
        virtual ~SystemInfoTest();

        virtual void SetUp ();
        virtual void TearDown ();

    private:

// static SystemInfo * objectUderTest;
};

#endif


#ifndef CFS_HAL_CPUAFFINITYTEST_HPP
#define CFS_HAL_CPUAFFINITYTEST_HPP
#include <gtest/gtest.h>
#include <cfs/hal/cpu/CpuAffinity.hpp>
class CpuAffinityTest : public ::testing::Test
{
    public:

        CpuAffinityTest();
        virtual ~CpuAffinityTest() = default;

        virtual void SetUp ();
        virtual void TearDown ();

    private:
};

#endif

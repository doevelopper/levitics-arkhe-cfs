
#include <cfs/hal/cpu/CpuInfo.hpp>

#include <iostream>
#include <unistd.h>
#include <fstream>

CpuInfo::CpuInfo()
    : m_processorIndex( 0 )
    , m_cpuNumber( 0 )
    , m_cpuTotalUsedRate( 0 )
    , m_cpuIdleRate( 0 )
{
}

int CpuInfo::cpuNumber () const
{
    return ( m_cpuNumber );
}

std::list < std::string >
CpuInfo::cpuinfoList ()
{
}

int
CpuInfo::cpuTotalUsedRate () const
{
    return ( m_cpuTotalUsedRate * 100 );
}

float
CpuInfo::cpuIdleRate () const
{
    return ( m_cpuIdleRate * 100 );
}

void
CpuInfo::readFile ()
{
// std::string procCpuInfo = "/proc/cpuinfo";
    std::ifstream procCpuInfo( "/proc/cpuinfo" );

    for ( std::string line; std::getline( procCpuInfo, line ); )
    {
    }
}

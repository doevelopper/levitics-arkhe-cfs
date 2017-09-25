
#include <thread>
#include <cfs/hal/SystemInfo.hpp>


std::uint64_t SystemInfo::m_totalRAM = 0;
std::uint64_t SystemInfo::m_freeRAM = 0;
std::uint64_t SystemInfo::m_totalGPUMemory = 0;
std::uint64_t SystemInfo::m_freeGPUMemory = 0;
std::uint32_t SystemInfo::m_numberOfChannels = 0;
std::uint32_t SystemInfo::m_numberOfThreads = 0;

SystemInfo::SystemInfo() {
}

SystemInfo::OperatingSystems
SystemInfo::getOperatingSystem ()
{
    return m_operatingSystem;
}

SystemInfo::ProcessorArchitectures
SystemInfo::getProcessorArchitecture ()
{
    return m_processorArchitecture;
}

std::uint64_t SystemInfo::getTotalRAM ()
{
    return m_totalRAM;
}

std::uint64_t SystemInfo::getFreeRAM ()
{
    return m_freeRAM;
}

std::uint64_t SystemInfo::getTotalGPUMemory ()
{
    return m_totalGPUMemory;
}

std::uint64_t SystemInfo::getFreeGPUMemory ()
{
    return m_freeGPUMemory;
}

std::uint32_t SystemInfo::getNumberOfChannels ()
{
    return m_numberOfChannels;
}

std::uint32_t SystemInfo::getNumberOfThreads ()
{
    return m_numberOfThreads;
}

void SystemInfo::discoverNumberOfThreads ()
{
    m_numberOfThreads = std::thread::hardware_concurrency();
}


#ifndef CFS_HAL_CPU_CPUINFO_HPP
#define CFS_HAL_CPU_CPUINFO_HPP

#include <list>
//#include <variant>
#include <string>

class CpuInfo 
{
public:
    CpuInfo();
    virtual ~CpuInfo() = default;

    int     cpuNumber() const;
    int     cpuTotalUsedRate() const;
    float   cpuIdleRate() const;

private:
    void    readFile();
    std::string cpuModelName();
    std::string numCores();
    std::list<std::string> cpuinfoList();
    std::list<std::string> processorKeyList();
    std::list<std::string> processorValueList();
//    std::variant<int, float>  cpuinfoMap();
//    std::variant<int, float>  cpuinfoMap(int processor);

    int     m_processorIndex;
    int     m_cpuNumber;
    float   m_cpuTotalUsedRate;
    float   m_cpuIdleRate;
    std::list<std::string> m_cpuinfoList;
};

#endif


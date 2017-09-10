#ifndef CFS_HAL_CPUAFFINITY_HPP
#define CFS_HAL_CPUAFFINITY_HPP

#include <algorithm>
#include <atomic>
#include <thread>
#include <unistd.h>

class CpuAffinity 
{
public:
    CpuAffinity();
    virtual ~CpuAffinity() = default;
    /*! 
     *  @brief Sets a CPU affinity mask for the current thread.
     */ 
    int setCpuCore() const;
private:
    /*! 
     *  @brief The CPU core for current thread.
     *         Default value is -1. It means that the CPU core is not selected yet.
     */ 
    //static thread_local int m_coreSelected;
    /*!
     * @brief This is the CPU core that will be selected on 
     *        the next call of setCpuCore() function.
     */ 
    mutable std::atomic<ushort> m_CpuCoreCounter;
    /*!
     * @brief The total number of CPU cores in the local system.
     */ 
    //const ushort m_totalCpuCores;
    /*!
     * @brief Sets a CPU affinity mask for the current thread.
     * 	     Returns the CPU core on which the current thread is now working
     *      // or -1 on error
     */ 
    int setCpu(const ushort& core) const;
};

#endif


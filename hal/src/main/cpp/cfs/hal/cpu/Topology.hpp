
#ifndef CFS_HAL_CPU_TOPOLOGY_HPP
#define CFS_HAL_CPU_TOPOLOGY_HPP

#include <cstdint>
#include <vector>

class Topology
{
    struct Processor
    {
        std::uint32_t systemId; /// > Identifier used by the system for this processor. E.g., for processor affinity.
        std::uint32_t threadId; /// > Thread ID within the the core
        std::uint32_t coreId; /// > Core ID within the package
        std::uint32_t packageId; /// > Package ID within the system
    };

    struct CpuCore
    {
// std::string processor {};
// std::string vendor {};
// std::string model {};
// std::string clockFreqMhz {};
// std::string cacheSize {};
// std::string flags {};
// std::string cpuFamily {};
// std::string bogoMips {};
    };

    public:

        Topology();
        virtual ~Topology() = default;

        using processorList = std::vector < Processor >;
        processorList const & processors () const;
        processorList const & processorsCore ( std::uint32_t coreId );
        processorList const & processorsPackage ( std::uint32_t packageId );

    private:

        processorList m_processors;
};

#endif

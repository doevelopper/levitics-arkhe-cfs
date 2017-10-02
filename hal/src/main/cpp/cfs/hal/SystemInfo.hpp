
#ifndef CFS_HAL_SYSTEMINFO_HPP
#define CFS_HAL_SYSTEMINFO_HPP
#include <cstdint>

/*!
 * @brief Static class that collects many pieces of useful system information such as OS,
 *        architecture, supported graphics APIs, etc.
 */

class SystemInfo
{
    enum class
    OperatingSystems : unsigned
    {
        Unknown = 0,
        Windows,
        MacOS,
        Linux
    };

    enum class
    ProcessorArchitectures : unsigned
    {
        Unknown = 0,
        x86,
        x64,
        IA64,
        ARM
    };

    public:

        SystemInfo();
        virtual ~SystemInfo() = default;
/*!
 * @brief Populates with all available system info.
 */
        static void
        initialize ();

/*!
 * @brief Forces a refresh of variables that can change during program lifetime. These include:
 *
 *     - Available RAM
 *     - Available GPU Memory
 *     - Available Channels
 *
 * This method is called automatically at the start of each frame.
 */
        static void
        refresh ();

/*!
 * @brief Helper method that logs all current system information.
 */
        static void
        logSystemInfo ();

/*!
 * @brief Returns the current running Operating System.
 */
        static OperatingSystems
        getOperatingSystem ();

/*!
 * @brief Returns the processor architecture for the system.
 */
        static ProcessorArchitectures
        getProcessorArchitecture ();

/*!
 * @brief Returns the total amount of physical RAM on this system (in bytes).
 * @note A return value of 0 indicates unknown. Either Ocular failed to retrieve the data, or refresh needs to be called.
 */
        static std::uint64_t
        getTotalRAM ();

/*!
 * @brief Returns the total amount of physical RAM that is available on the system (in bytes).
 * @note A return value of 0 indicates unknown. Either Ocular failed to retrieve the data, or refresh needs to be called.
 */
        static std::uint64_t
        getFreeRAM ();

/*!
 * @brief Returns the total amount of memory on the GPUs (both used and unused) (in bytes).
 * @note A return value of 0 indicates unknown. Either Ocular failed to retrieve the data, or refresh needs to be called.
 */
        static std::uint64_t
        getTotalGPUMemory ();

/*!
 * @brief Returns the total amount of memory that is free and not in use on the GPUs (in bytes).
 * @note A return value of 0 indicates unknown. Either Ocular failed to retrieve the data, or refresh needs to be called.
 */
        static std::uint64_t
        getFreeGPUMemory ();

/*!
 * @brief Returns number of output channels (monitors, etc.) on the system.
 * @note A return value of 0 indicates unknown. Either Ocular failed to retrieve the data, or refresh needs to be called.
 */
        static std::uint32_t
        getNumberOfChannels ();

/*!
 *  @brief Returns the number of supported concurrent threads.
 */
        static std::uint32_t
        getNumberOfThreads ();

    protected:

        static void
        discoverOperatingSystem ();
        static void
        discoverProcessorArchitecture ();
        static void
        discoverEndianness ();
        static void
        discoverOpenGLLevel ();
        static void
        discoverDirectXLevel ();
        static void
        discoverInstalledRAM ();
        static void
        discoverInstalledGPUMemory ();
        static void
        discoverNumberOfThreads ();

// ----------------------------------------
// System specific that can change during program runtime
// These are called in refresh

        static void
        discoverAvailableGPUMemory ();
        static void
        discoverAvailableRAM ();
        static void
        discoverChannels ();

    private:

        static OperatingSystems m_operatingSystem;
        static ProcessorArchitectures m_processorArchitecture;
        static std::uint64_t m_totalRAM;
        static std::uint64_t m_freeRAM;
        static std::uint64_t m_totalGPUMemory;
        static std::uint64_t m_freeGPUMemory;

        static std::uint32_t m_numberOfChannels;
        static std::uint32_t m_numberOfThreads;
};

#endif

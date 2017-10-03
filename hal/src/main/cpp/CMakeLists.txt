set(cppsrc
    cfs/hal/SystemInfo
    cfs/hal/ResourceUsage
    cfs/hal/ResourceLimit
    cfs/hal/cpu/CpuAffinity
    cfs/hal/cpu/CpuInfo
    cfs/hal/cpu/Topology
 )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_library(${PROJECT_NAME}-hal STATIC ${cppsrc})
target_include_directories(${PROJECT_NAME}-hal PUBLIC ${CMAKE_CURRENT_LIST_DIR})
 set(cppsrc
 	cfs/hal/SystemInfo
        cfs/hal/cpu/CpuAffinity
 	cfs/hal/cpu/CpuInfo
 	cfs/hal/cpu/Topology
 )

 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

add_library(${PROJECT_NAME}-hal STATIC ${cppsrc})


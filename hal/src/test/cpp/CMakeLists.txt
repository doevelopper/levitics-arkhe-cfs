 set(cppsrc
 	cfs/hal/CpuAffinityTest
 )

 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

 add_library(${PROJECT_NAME}-halTest STATIC ${cppsrc})

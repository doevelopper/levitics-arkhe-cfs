 set(cppsrc
 	cfs/hal/CpuAffinity
 )

 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

 add_library(${PROJECT_NAME}-hal STATIC ${cppsrc})

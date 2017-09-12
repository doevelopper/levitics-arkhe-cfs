 set(cppsrc
        cfs/osal/time/HRTimerTest
        cfs/osal/time/TimeSpanTest
 	cfs/osal/SemaphoreTest
 )

 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

add_library(${PROJECT_NAME}-osalTest STATIC ${cppsrc})

target_include_directories(${PROJECT_NAME}-osalTest PUBLIC ${CMAKE_CURRENT_LIST_DIR})
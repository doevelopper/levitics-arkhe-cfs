 set(cppsrc
        cfs/osal/time/HRTimer
        cfs/osal/time/TimeSpan
 	cfs/osal/Semaphore
 )

 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

 add_library(${PROJECT_NAME}-osal STATIC ${cppsrc})
#target_compile_features(${PROJECT_NAME}-osal PUBLIC cxx_constexpr cxx_strong_enums cxx_auto_type cxx_range_for)
# PUBLIC adds both:
#     1) include directories for compile library and
#     2) include directories for library's interface
target_include_directories(${PROJECT_NAME}-osal PUBLIC ${CMAKE_CURRENT_LIST_DIR}) # osal or . or ${CMAKE_CURRENT_LIST_DIR} or ${CMAKE_CURRENT_SOURCE_DIR}


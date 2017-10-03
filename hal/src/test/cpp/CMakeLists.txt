
set(libTargetName ${PROJECT_NAME}-halTest)
set(exeTargetName ${PROJECT_NAME}-halTest.bin)

 set(cppsrc
 	cfs/SystemInfoTest
 	cfs/hal/CpuAffinityTest
 )

#get_filename_component(MODULE_ROOT_DIRECTORY ${CMAKE_PARENT_LIST_FILE} PATH)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

#add_executable (${exeTargetName} ${cppsrc})

add_library(${libTargetName} STATIC ${cppsrc})
#
#target_include_directories(${libTargetName} PUBLIC ${CMAKE_CURRENT_LIST_DIR})

#target_link_libraries (${libTargetName}
##    ${TEST_THIRD_PARTY_LIB_MAIN}
#
#    gmock 
#    gtest 
#    benchmark 
#    pthread
#    ${PROJECT_NAME}-hal
#    gmock_main
#)

#add_test(
#    NAME ${PROJECT_NAME}-halTest
#    COMMAND ${PROJECT_NAME}-halTest
#)

#get_filename_component(PARENT_DIR ${CMAKE_PARENT_LIST_FILE} PATH)

#if(ENABLE_COVERAGE)
#   add_coverage_targets(${PROJECT_NAME}-halTest 
#        ${PROJECT_NAME}-halTest 
#        ${MODULE_ROOT_DIRECTORY}
#    )
#endif(ENABLE_COVERAGE)
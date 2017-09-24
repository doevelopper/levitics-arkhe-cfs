 set(testsrc
    cfs/AppTest
 )

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

add_library(${PROJECT_NAME}-cfsTest STATIC ${testsrc})
target_include_directories(${PROJECT_NAME}-cfsTest PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries (${PROJECT_NAME}-cfsTest 
    ${TEST_THIRD_PARTY_LIB_MAIN}
    pthread
    ${PROJECT_NAME}-cfs
)


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(itsrc 
    cfs/hal/Hal
)
#add_executable(${PROJECT_NAME}-hal-ItTest STATIC ${itsrc})
add_library(${PROJECT_NAME}-hal-ItTest STATIC ${itsrc})

target_link_libraries (${PROJECT_NAME}-hal-ItTest 
    ${TEST_THIRD_PARTY_LIB}
    ${INTEG_TEST_THIRD_PARTY_LIB_MAIN}
    pthread
    ${PROJECT_NAME}-halTest
    ${PROJECT_NAME}-hal
)

#add_dependencies(${PROJECT_NAME}-hal-ItTest  ${PROJECT_NAME}-halTest ${PROJECT_NAME}-hal)

#add_custom_command(TARGET RunAllTests
#    POST_BUILD
#    COMMAND RunTests
#    COMMAND ${PROJECT_NAME}-hal-ItTest 55555 &
#    COMMAND cucumber -s ${CMAKE_SOURCE_DIR}/features
#)
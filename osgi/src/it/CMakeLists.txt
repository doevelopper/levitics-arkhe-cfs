
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(itsrc 
    cfs/Osgi
)
add_library(${PROJECT_NAME}-osgi-ItTest STATIC ${itsrc})

target_link_libraries (${PROJECT_NAME}-osgi-ItTest 
    ${TEST_THIRD_PARTY_LIB}
    ${INTEG_TEST_THIRD_PARTY_LIB_MAIN}
    pthread
    ${PROJECT_NAME}-osgi
)
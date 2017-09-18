
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(itsrc 
    cfs/osal/Osal
)
add_library(${PROJECT_NAME}-osal-ItTest STATIC ${itsrc})

target_link_libraries (${PROJECT_NAME}-osal-ItTest 
    ${TEST_THIRD_PARTY_LIB}
    ${INTEG_TEST_THIRD_PARTY_LIB_MAIN}
    pthread
    ${PROJECT_NAME}-osal
)
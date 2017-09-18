
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

set(itsrc 
    cfs/Cfs
)
add_library(${PROJECT_NAME}-cfs-ItTest STATIC ${itsrc})

target_link_libraries (${PROJECT_NAME}-cfs-ItTest 
    ${TEST_THIRD_PARTY_LIB}
    ${INTEG_TEST_THIRD_PARTY_LIB_MAIN}
    pthread
    ${PROJECT_NAME}-cfs
)
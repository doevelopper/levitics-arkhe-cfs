
if(ENABLE_FORMATING_STYLE)
    apply_style_targets(
        ${PROJECT_NAME}-hal
        ${CMAKE_CURRENT_BINARY_DIR}
    )
endif(ENABLE_FORMATING_STYLE)

if(ENABLE_CPPCHECK)
    ADD_CPPCHECK_ANALYSIS(
        ${PROJECT_NAME}-hal
        ${CMAKE_CURRENT_BINARY_DIR}
    )
endif(ENABLE_CPPCHECK)


add_subdirectory (src/main/cpp)
add_subdirectory (src/test/cpp)
add_subdirectory (src/it)

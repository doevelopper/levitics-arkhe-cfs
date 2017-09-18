
if(ENABLE_CPPLINT)
    CPPLINT_RECURSIVE(
        ${PROJECT_NAME}Osgi                                   #target_name.The name of the target to define. Your program should depend on it to invoke cpplint.
        ${CMAKE_CURRENT_SOURCE_DIR}                           #src_folder.The folder to recursively run cpplint.
        ${CORE_MODULE_ROOT_DIRECTORY}                         #root_folder.The root folder used to determine desired include-guard comments.
#        "${TARGET_BUILD_DIRECTORY}/lint/${PROJECT_NAME}Core" #bin_folder.The temporary build folder to store a cpplint history file.
    )
endif(ENABLE_CPPLINT)


if(ENABLE_CPPCHECK)
    ADD_CPPCHECK_ANALYSIS(
        ${PROJECT_NAME}Osgi
        ${CMAKE_CURRENT_BINARY_DIR}
    )
endif(ENABLE_CPPCHECK)

if(ENABLE_FORMATING_STYLE)
    apply_style_targets(
        ${PROJECT_NAME}Osgi
        ${CMAKE_CURRENT_BINARY_DIR}
    )
endif(ENABLE_FORMATING_STYLE)


if(ENABLE_CYCLOMATIC_COMPLEXITY)
    CYCLOMATIC_COMPLEXITY_ANALYZER( 
        ${PROJECT_NAME}Osgi
        ${CMAKE_CURRENT_SOURCE_DIR}
    )
endif(ENABLE_CYCLOMATIC_COMPLEXITY)



add_subdirectory (src/main/cpp)
add_subdirectory (src/test/cpp)
add_subdirectory (src/it)
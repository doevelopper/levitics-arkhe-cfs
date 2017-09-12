project(levitics-arkhe-cfs CXX)
cmake_minimum_required( VERSION 3.8 FATAL_ERROR)

set(PROJECT_NAME_MAJOR_VERSION       3)
set(PROJECT_NAME_MINOR_VERSION       7)
set(PROJECT_NAME_MICRO_VERSION       0)
set(PROJECT_NAME_PATCH_VERSION       0)
set(PROJECT_NAME_REVISION_VERSION    "dev")

set(PROJECT_DESCRIPTION "dev")
set(PROJECT_VERSION_MAJOR       1)
set(PROJECT_VERSION_MINOR       5)
set(PROJECT_VERSION_PATCH       2)
set(PROJECT_VERSION_TWEAK       1101)
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

add_definitions(-DPROJECT_VERSION_MAJOR=1)
add_definitions(-DPROJECT_VERSION_MINOR=0)
add_definitions(-DPROJECT_VERSION_MICRO=0)
add_definitions(-DPROJECT_VERSION_PATCH=${PROJECT_NAME})

add_definitions(-DAPPLICATIONNAME=${PROJECT_VERSION_PATCH})
add_definitions(-DAPP_VERSION_STR="${${PROJECT_NAME}_MAJOR_VERSION}.${${PROJECT_NAME}_MINOR_VERSION}.${${PROJECT_NAME}_MICRO_VERSION}")

option(ENABLE_QA_CHECK                  "Software quality. Conformance to one or more standards"    OFF)
option(ENABLE_COVERAGE                  "Build the project with coverage support"                   OFF)
option(ENABLE_CPPLINT                   "Ensure that code conforms to Google's coding style guides" OFF)
option(ENABLE_FORMATING_STYLE           "Code Beautifier"                                           OFF)
option(ENABLE_CYCLOMATIC_COMPLEXITY     "Cyclomatic Complexity Analyzer"                            OFF)
option(ENABLE_CPPCHECK                  "Static code analysis tool "                                OFF)
option(ANALYZE_MEMORY                   "Dynamic analyzer: detector of uninitialized reads."        OFF)
option(ANALYZE_ADDRESS                  "Dynamic analyzer: fast memory error detector. "            OFF)
option(ANALYZE_THREAD                   "Dynamic analyzer: tool that detects data races. "          OFF)
option(ANALYZE_UNDEFINED                "Dynamic analyzer: undefined behavior checker. "            OFF)
option(ANALYZE_DATAFLOW                 "Dynamic analyzer: general dynamic dataflow analysis."      OFF)

list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/modules"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/toolChains"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/macros"
    "${CMAKE_SOURCE_DIR}/src/test/resources/config/modules"
)

set (NAMESPACE "CFSA")

set(TEST_THIRD_PARTY_LIB gmock gtest benchmark)
set(INTEG_TEST_THIRD_PARTY_LIB cucumber-cpp-nomain) #cucumber-cpp 

include(LibrarySettings)
include(CompilerOption)
include(buildLifeCycle)

add_subdirectory (hal)
add_subdirectory (osal)
add_subdirectory (osgi)
add_subdirectory (cf)
add_subdirectory (cfe)

add_subdirectory (src/main/cpp)
add_subdirectory (src/test/cpp)
add_subdirectory (src/it)
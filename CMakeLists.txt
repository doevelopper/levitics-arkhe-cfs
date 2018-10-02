#       CMakeLists.txt
#
#               Copyright (c) 2014-2017 Nicolas J. FURY
#
#        Permission is hereby granted, free of charge, to any person obtaining
#        a copy of this software and associated documentation files (the
#        "Software"), to deal in the Software without restriction, including
#        without limitation the rights to use, copy, modify, merge, publish,
#        distribute, sublicense, and/or sell copies of the Software, and to
#        permit persons to whom the Software is furnished to do so, subject to
#        the following conditions:
#
#        The above copyright notice and this permission notice shall be
#        included in all copies or substantial portions of the Software.
#
#        THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#        EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#        MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#        NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
#        LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#        OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
#        WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


project(levitics-arkhe-cfs CXX)

cmake_minimum_required( VERSION 3.10 FATAL_ERROR)

set(GIT_REVISION 0)
set(PROJECT_NAME_MAJOR_VERSION           1)
set(PROJECT_NAME_MINOR_VERSION           0)
set(PROJECT_NAME_MICRO_VERSION           0)
set(PROJECT_NAME_PATCH_VERSION           0)
set(PROJECT_NAME_BUILD_VERSION ${GIT_REVISION})
set(PROJECT_NAME_VERSION_EXTENSION      "")
set(PROJECT_NAME_REVISION_VERSION    "dev")

set(PROJECT_DESCRIPTION              "dev")
set(PROJECT_VERSION_MAJOR                1)
set(PROJECT_VERSION_MINOR                0)
set(PROJECT_VERSION_PATCH                0)
set(PROJECT_VERSION_TWEAK                1)

set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")


list(APPEND CMAKE_MODULE_PATH
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/modules"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/toolChains"
    "${CMAKE_SOURCE_DIR}/src/main/resources/config/macros"
    "${CMAKE_SOURCE_DIR}/src/test/resources/config/modules"
)


include(ProcessorCount)
ProcessorCount(Ncpu)

include(TestBigEndian)
TEST_BIG_ENDIAN(IS_BIG_ENDIAN)
if(IS_BIG_ENDIAN)
    message(FATAL_ERROR "Big endian isn't supported !!!")
endif(IS_BIG_ENDIAN)

include(buildLifeCycle)
include(CodingStyle)
include(cppcheck)
include(cyclomatic)
include(CpplintWrapper)

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
option(WARNINGS_ARE_ERRORS              "Treat warnings as errors"                                  OFF)
option(WARNINGS_ANSI_ISO                "Issue all the mandatory diagnostics Listed in C standard"  ON)

set (NSPACE "CFS")
#add_definitions(-DNSPACE="CFSA")

set(TEST_THIRD_PARTY_LIB gmock gtest benchmark)
set(TEST_THIRD_PARTY_LIB_MAIN gmock gtest benchmark gmock_main)
set(INTEG_TEST_THIRD_PARTY_LIB cucumber-cpp-nomain)
set(INTEG_TEST_THIRD_PARTY_LIB_MAIN cucumber-cpp)

#set(CMAKE_C_COMPILER           "/usr/bin/gcc-7")
#set(CMAKE_C_COMPILER_AR        "/usr/bin/gcc-ar-7")
#set(CMAKE_C_COMPILER_RANLIB    "/usr/bin/gcc-ranlib-7")
#set(CMAKE_CXX_COMPILER         "/usr/bin/g++-7")
#set(CMAKE_CXX_COMPILER_AR      "/usr/bin/gcc-ar-7")
#set(CMAKE_CXX_COMPILER_RANLIB  "/usr/bin/gcc-ranlib-7")
#set(CMAKE_CXX_COMPILER_VERSION "7.0.1")
#set(CMAKE_AR                   "/usr/bin/gcc-ar-7")
#set(CMAKE_NM                   "/usr/bin/gcc-nm-7")
#set(CMAKE_OBJCOPY              "/usr/bin/objcopy")
#set(CMAKE_OBJDUMP              "/usr/bin/objdump")
#set(CMAKE_RANLIB 


include(PreventInSourceBuilds)
include(LibrarySettings)
include(CompilerOption)
include(CMakeSettings)
include(macros)
include(aol)
include(GccCoverage)

enable_testing()

generateGitInfo()
getGitInfo()
#TODAY(APP_BUILD_DATE)

configure_file("${PROJECT_SOURCE_DIR}/src/main/resources/Config.hpp.in"
               "${CMAKE_CURRENT_BINARY_DIR}/cfs/Config.hpp"
                @ONLY)

#include_directories(${CMAKE_CURRENT_BINARY_DIR}) # needed for generated files
#message (STATUS "PROJECT_BINARY_DIR ${PROJECT_BINARY_DIR}")

#add_subdirectory (hal)
#add_subdirectory (osal)
#add_subdirectory (osgi)
#add_subdirectory (cf)
#add_subdirectory (cfe)

#add_subdirectory (src/main/cpp)
#add_subdirectory (src/test/cpp)
#add_subdirectory (src/it)

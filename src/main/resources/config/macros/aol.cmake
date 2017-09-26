#The triple has the general format <arch><sub>-<vendor>-<sys>-<abi>, where:

#        arch    = x86, arm, thumb, mips, etc.
#        sub     = for ex. on ARM: v5, v6m, v7a, v7m, etc.
#        vendor  = pc, apple, nvidia, ibm, etc.
#        sys     = none, linux, win32, darwin, cuda, etc.
#        abi     = eabi, gnu, android, macho, elf, etc.

set(AOL "${CMAKE_HOST_SYSTEM_NAME}-${CMAKE_CXX_COMPILER_ID}_GCC_${CMAKE_CXX_COMPILER_VERSION}-${CMAKE_SYSTEM_PROCESSOR}")


set(BUILD_DIRECTORY ${CMAKE_BINARY_DIR})
set(TARGET_BUILD_DIRECTORY ${BUILD_DIRECTORY}/${AOL}-${CMAKE_BUILD_TYPE})
set(ROOT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR})
set(ROOT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_INSTALL_PREFIX ${AOL}-${CMAKE_BUILD_TYPE})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIRECTORY}/${AOL}-${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_DIRECTORY}/${AOL}-${CMAKE_BUILD_TYPE}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIRECTORY}/${AOL}-${CMAKE_BUILD_TYPE}/bin)

set( DLT_MAJOR_VERSION 2)
set( DLT_MINOR_VERSION 17)
set( DLT_PATCH_LEVEL 0)
set( DLT_VERSION ${DLT_MAJOR_VERSION}.${DLT_MINOR_VERSION}.${DLT_PATCH_LEVEL})
set( DLT_VERSION_STATE UNSTABLE )
set( DLT_REVISION "")


include(TestBigEndian)
TEST_BIG_ENDIAN( DLT_BIGENDIAN )
if( DLT_BIGENDIAN )
	add_definitions( -DBYTE_ORDER=BIG_ENDIAN )
else ( DLT_BIGENDIAN )
	add_definitions( -DBYTE_ORDER=LITTLE_ENDIAN )
endif ( DLT_BIGENDIAN )

include(CheckIncludeFiles)
CHECK_INCLUDE_FILES( arpa/inet.h HAVE_ARPAINET_H)
CHECK_INCLUDE_FILES( fcntl.h HAVE_FCNTL_H)
CHECK_INCLUDE_FILES( float.h HAVE_FLOAT_H)
CHECK_INCLUDE_FILES( limits.h HAVE_LIMITS_H)
CHECK_INCLUDE_FILES( netdb.h HAVE_NETDB_H)
CHECK_INCLUDE_FILES( netinet/in.h HAVE_NETINETIN_H)
CHECK_INCLUDE_FILES( stddef.h HAVE_STDDEF_H)
CHECK_INCLUDE_FILES( stdint.h HAVE_STDINT_H)
CHECK_INCLUDE_FILES( stdlib.h HAVE_STDLIB_H)
CHECK_INCLUDE_FILES( string.h HAVE_STRING_H)
CHECK_INCLUDE_FILES( strings.h HAVE_STRINGS_H)
CHECK_INCLUDE_FILES( sys/ioctl.h HAVE_SYSIOCTL_H)
CHECK_INCLUDE_FILES( sys/socket.h HAVE_SYSSOCKET_H)
CHECK_INCLUDE_FILES( sys/time.h HAVE_SYSTIME_H)

if( WITH_SYSTEMD_WATCHDOG OR WITH_SYSTEMD )
    set(CMAKE_REQUIRED_INCLUDES "${CMAKE_SOURCE_DIR}/systemd/3rdparty/")
    CHECK_INCLUDE_FILES( sd-daemon.h HAVE_SYSTEMD_H)
endif ( WITH_SYSTEMD_WATCHDOG OR WITH_SYSTEMD )

CHECK_INCLUDE_FILES( unistd.h HAVE_UNISTD_H)
CHECK_INCLUDE_FILES( sys/ipc.h HAVE_SYSIPC_H)
CHECK_INCLUDE_FILES( netdb.h HAVE_NETDB_H)
CHECK_INCLUDE_FILES( ctype.h HAVE_CTYPE_H)
CHECK_INCLUDE_FILES( signal.h HAVE_SIGNAL_H)
CHECK_INCLUDE_FILES( syslog.h HAVE_SYSLOG_H)
CHECK_INCLUDE_FILES( sys/stat.h HAVE_SYSSTAT_H)
CHECK_INCLUDE_FILES( linux/stat.h HAVE_LINUXSTAT_H)
CHECK_INCLUDE_FILES( sys/uio.h HAVE_SYSUIO_H)
CHECK_INCLUDE_FILES( termios.h HAVE_TERMIOS_H)
CHECK_INCLUDE_FILES( unistd.h HAVE_UNISTD_H)

include(CheckFunctionExists)
CHECK_FUNCTION_EXISTS( bzero HAVE_FUNC_BZERO)
CHECK_FUNCTION_EXISTS( clock_gettime HAVE_FUNC_CLOCKGETTIME)
CHECK_FUNCTION_EXISTS( floor HAVE_FUNC_FLOOR)
CHECK_FUNCTION_EXISTS( fork HAVE_FUNC_FORK)
CHECK_FUNCTION_EXISTS( gethostbyname HAVE_FUNC_GETHOSTBYNAME)
CHECK_FUNCTION_EXISTS( gettimeofday HAVE_FUNC_GETTIMEBYDAY)
CHECK_FUNCTION_EXISTS( inet_ntoa HAVE_FUNC_INETNTOA)
CHECK_FUNCTION_EXISTS( malloc HAVE_FUNC_MALLOC)
CHECK_FUNCTION_EXISTS( memmove HAVE_FUNC_MEMMOVE)
CHECK_FUNCTION_EXISTS( memset HAVE_FUNC_MEMSET)
CHECK_FUNCTION_EXISTS( mkfifo HAVE_FUNC_MKFIFO)
CHECK_FUNCTION_EXISTS( select HAVE_FUNC_SELECT)
CHECK_FUNCTION_EXISTS( socket HAVE_FUNC_SOCKET)
CHECK_FUNCTION_EXISTS( strchr HAVE_FUNC_STRCHR)
CHECK_FUNCTION_EXISTS( strerror HAVE_FUNC_STRERROR)
CHECK_FUNCTION_EXISTS( strstr HAVE_FUNC_STRSTR)
CHECK_FUNCTION_EXISTS( strtol HAVE_FUNC_STRTOL)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
get_filename_component(PARENT_DIR ${CMAKE_PARENT_LIST_FILE} PATH)

#if(WITH_CHECK_CONFIG_FILE)
configure_file(${PARENT_DIR}/../resources/config/cmake/config.h.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/cfs/osgi/dlt/config.h
 )
#endif(WITH_CHECK_CONFIG_FILE)


configure_file(${PARENT_DIR}/../resources/config/cmake/dlt_version.h.cmake 
    ${CMAKE_CURRENT_BINARY_DIR}/cfs/osgi/dlt/dlt_version.h 
    @ONLY
)


option(BUILD_SHARED_LIBS      "Set to OFF to build static libraries"                                                ON )
option(WITH_SYSTEMD           "Set to ON to create unit files and systemd check on dlt-daemon startup"              OFF)
option(WITH_SYSTEMD_WATCHDOG  "Set to ON to use the systemd watchdog in dlt-daemon"                                 OFF)
option(WITH_SYSTEMD_JOURNAL   "Set to ON to use the systemd journal in dlt-system"                                  OFF)
option(WITH_DOC               "Set to ON to build documentation target"                                             OFF )
option(WITH_MAN               "Set to ON to build man pages"                                                        ON )
option(WITH_CHECK_CONFIG_FILE "Set to ON to create a configure file of CheckIncludeFiles and CheckFunctionExists "  OFF )
option(WITH_TESTSCRIPTS       "Set to ON to run CMakeLists.txt in testscripts"                                      OFF )
option(WITH_GPROF             "Set -pg to compile flags"                                                            OFF )
option(WITH_DLTTEST	      "Set to ON to build with modifications to test User-Daemon communication with corrupt messages" OFF)
option(WITH_DLT_SHM_ENABLE    "EXPERIMENTAL! Set to ON to use shared memory as IPC. EXPERIMENTAL!"                  OFF )
option(WTIH_DLT_ADAPTOR       "Set to ON to build src/adaptor binaries"                                             ON)
option(WITH_DLT_CONSOLE       "Set to ON to build src/console binaries"                                             ON)
option(WITH_DLT_EXAMPLES      "Set to ON to build src/examples binaries"                                            ON)
option(WITH_DLT_SYSTEM        "Set to ON to build src/system binaries"                                              ON)
option(WITH_DLT_DBUS          "Set to ON to build src/dbus binaries"                                                ON)
option(WITH_DLT_TESTS         "Set to ON to build src/test binaries"                                                ON)
option(WITH_DLT_UNIT_TESTS    "Set to ON to build gtest framework and tests/binaries"                               OFF)
option(WITH_DLT_CXX11_EXT     "Set to ON to build C++11 extensions"                                                 OFF)
option(WITH_DLT_COREDUMPHANDLER     "EXPERIMENTAL! Set to ON to build src/core_dump_handler binaries. EXPERIMENTAL" OFF)
option(WITH_DLT_LOGSTORAGE_CTRL_UDEV "PROTOTYPE! Set to ON to build logstorage control application with udev support" OFF)
option(WITH_DLT_LOGSTORAGE_CTRL_PROP "PROTOTYPE! Set to ON to build logstorage control application with proprietary support" OFF)
option(WITH_DLT_USE_IPv6       "Set to ON for IPv6 support"                                                         ON)
option(WITH_DLT_KPI        	  "Set to ON to build src/kpi binaries"                                             ON)
option(WITH_DLT_FATAL_LOG_TRAP "Set to ON to enable DLT_LOG_FATAL trap (trigger segv inside dlt-user library)"      OFF)


set(LIBRA dbus-1)

add_definitions( -D_GNU_SOURCE )

if(WITH_DLTTEST)
	add_definitions( -DDLT_TEST_ENABLE)
endif(WITH_DLTTEST)

if (WITH_DLT_UNIT_TESTS)
    add_definitions(-DDLT_UNIT_TESTS)
endif(WITH_DLT_UNIT_TESTS)

if(WITH_DLT_SHM_ENABLE)
    add_definitions( -DDLT_SHM_ENABLE)
endif(WITH_DLT_SHM_ENABLE)

if(WITH_DLT_USE_IPv6)
    add_definitions( -DDLT_USE_IPv6)
endif(WITH_DLT_USE_IPv6)


 set(cppsrc
        cfs/osgi/edac/callstack/ABIDemangling
 	cfs/osgi/edac/ErrorHandler
 	cfs/osgi/edac/Error
        cfs/osgi/edac/Exception
 	cfs/osgi/edac/Activator
 )

 set(CMAKE_INCLUDE_CURRENT_DIR ON)
 set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

 add_library(${PROJECT_NAME}-osgi STATIC ${cppsrc})

# PUBLIC adds both:
#     1) include directories for compile library and
#     2) include directories for library's interface
# target_include_directories(${PROJECT_NAME}-osgi PUBLIC osgi) # osgi or . or ${CMAKE_CURRENT_LIST_DIR} or ${CMAKE_CURRENT_SOURCE_DIR}

# set(cppsrc
# osgi/Osgi
# )
# set(CMAKE_INCLUDE_CURRENT_DIR ON)
# set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

# add_library(${PROJECT_NAME}-osgi-test STATIC ${cppsrc})

# PUBLIC adds both:
#     1) include directories for compile library and
#     2) include directories for library's interface
# target_include_directories(${PROJECT_NAME}-osgi-test PUBLIC osgi) # osgi or . or ${CMAKE_CURRENT_LIST_DIR} or ${CMAKE_CURRENT_SOURCE_DIR}

# add_executable(
# 	gtest_dlt_common 
# 	gtest_dlt_common.cpp
# )
# add_executable(
# 	gtest_dlt_user 
# 	gtest_dlt_user.cpp
# )
#add_executable(
#	gtest_dlt_daemon_common 
#	gtest_dlt_daemon_common.cpp 
#	../src/daemon/dlt_daemon_common.c)
#
#add_executable(
#	dlt_test_receiver 
#	dlt_test_receiver.c
#)
#
#add_executable(
#	dlt_env_ll_unit_test 
#	dlt_env_ll_unit_test.cpp
#)
#
#add_executable(
#	dlt-test-preregister-context 
#	dlt-test-preregister-context.c
#)
#
#add_executable(
#	gtest_dlt_daemon_gateway 
#	gtest_dlt_daemon_gateway.cpp
#)
#
#add_executable(
#	gtest_dlt_daemon_event_handler 
#	gtest_dlt_daemon_event_handler.cpp
#)
#
#target_link_libraries(
#	gtest_dlt_common 
#	gtest gtest_main 
#	dlt
#)
#
#target_link_libraries(
#	gtest_dlt_user 
#	gtest gtest_main 
#	dlt
#)
#
#target_link_libraries(
#	gtest_dlt_daemon_common 
#	gtest gtest_main 
#	dlt
#)
#
#target_link_libraries(
#	dlt_test_receiver 
#	dlt
#)
#
#target_link_libraries(
#	dlt_env_ll_unit_test 
#	gtest 
#	gtest_main 
#	dlt
#)
#
#target_link_libraries(
#	dlt-test-preregister-context 
#	gtest 
#	gtest_main 
#	dlt
#)
#
#target_link_libraries(
#	gtest_dlt_daemon_gateway 
#	gtest gtest_main 
#	dlt_daemon
#)
#
#target_link_libraries(
#	gtest_dlt_daemon_event_handler 
#	gtest 
#	gtest_main 
#	dlt_daemon
#)
#
#add_executable(
#	dlt-test-cpp-extension 
#	dlt-test-cpp-extension.cpp
#)
#set_target_properties(dlt-test-cpp-extension PROPERTIES COMPILE_FLAGS "-std=gnu++0x")
#
#target_link_libraries(
#	dlt-test-cpp-extension 
#	gtest 
#	gtest_main 
#	dlt
#)
  
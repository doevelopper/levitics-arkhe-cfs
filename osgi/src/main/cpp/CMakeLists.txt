set(cppsrc
	cfs/osgi/Osgi
)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR_IN_INTERFACE ON)

add_library(${PROJECT_NAME}-osgi STATIC ${cppsrc})

# PUBLIC adds both:
#     1) include directories for compile library and
#     2) include directories for library's interface
target_include_directories(${PROJECT_NAME}-osgi PUBLIC osgi) # osgi or . or ${CMAKE_CURRENT_LIST_DIR} or ${CMAKE_CURRENT_SOURCE_DIR}

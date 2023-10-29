cmake_minimum_required(VERSION 3.23)
project(demo)

set(CMAKE_CXX_STANDARD 23)

# define a library to be built off the source code
add_library(mylib STATIC functions.cpp)
set_target_properties(mylib PROPERTIES POSITION_INDEPENDENT_CODE ON)

# defined pybind output (module) with bindings
# this requires linking the module to the created library
find_package(pybind11 REQUIRED)
pybind11_add_module(python_example STATIC binder.cpp)
target_link_libraries(python_example PRIVATE mylib)

# define standard build output (main) to debug the code
add_executable(python_example_main main.cpp)
target_link_libraries(python_example_main PRIVATE mylib)




cmake_minimum_required(VERSION 2.8)
project(properties)
set(CMAKE_CXX_FLAGS "-std=c++11 -L/home/zhm/git/test/build -fno-elide-constructors -O0") # -rpath-link

# link_directories(${CMAKE_SOURCE_DIR}/build) # -rpath
add_executable(properties main.cc Foo.cc)
target_link_libraries(properties pthread)
# target_link_libraries(properties Foo)

add_executable(smartPtr smartPtr.cpp)
target_link_libraries(smartPtr pthread)
add_executable(copy_elision copy_elision.cpp)
add_executable(virtual_destroy virtual_destroy.cpp)
add_executable(auto_and_range_for auto_and_range_for.cpp)
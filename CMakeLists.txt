cmake_minimum_required(VERSION 2.8)
project(properties)
# set(CMAKE_CXX_FLAGS "-std=c++11 -L/home/zhm/git/test/build -fno-elide-constructors -O0") # -rpath-link

add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)
# 编译器和C++标准
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
# clang++
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++ -Wl,-rpath,$ENV{HOME}/bin/llvm/lib -Wno-unused-command-line-argument") # clang++, -Wl选项用来比避免lldb-mi找不到链接库
# set(LIBRARIES_TO_LINK "c++abi")

# link_directories(${CMAKE_SOURCE_DIR}/build) # -rpath
add_executable(properties main.cc Foo.cc)
target_link_libraries(properties pthread)
# target_link_libraries(properties Foo)
add_executable(smartPtr smartPtr.cpp)
target_link_libraries(smartPtr pthread)
add_executable(copy_elision copy_elision.cpp)
add_executable(virtual_destroy virtual_destroy.cpp)
add_executable(tls_static_var tls_static_var.cpp)
target_link_libraries(tls_static_var pthread)
add_executable(multithreads_fork multithreads_fork.cpp)
target_link_libraries(multithreads_fork pthread)
add_executable(function function.cpp)
add_executable(auto_and_range_for auto_and_range_for.cpp)
add_executable(time time.cpp)
add_executable(emplace emplace.cpp)
add_executable(pod POD.cpp)
add_executable(storage_duration storage_duration.cpp)
target_link_libraries(storage_duration pthread)
project(mocking-rest CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(3rdParty/gtest)

add_library(server-core src/server.cpp)
target_include_directories(server-core PUBLIC ${CMAKE_SOURCE_DIR}/src)

enable_testing()

macro(add_test_new name)
    add_executable(${name} tests/${name}.cpp)
    target_include_directories(${name} PUBLIC ${CMAKE_SOURCE_DIR})
    target_link_libraries(${name} gmock gmock_main server-core)
    add_test(${name} ${name})
endmacro()

add_test_new(interface_mocking)

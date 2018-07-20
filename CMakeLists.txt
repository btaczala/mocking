project(mocking-rest CXX)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(3rdParty/gtest)

add_library(server-core src/server.cpp)
target_include_directories(server-core PUBLIC ${CMAKE_SOURCE_DIR}/src)


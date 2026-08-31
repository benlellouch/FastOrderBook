cmake_minimum_required(VERSION 3.10)

project (FastOrderBook)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB source_files "${source_dir}/*.cpp")

add_executable (FastOrderBook ${source_files})

find_package(PkgConfig REQUIRED)
pkg_check_modules(UUID REQUIRED uuid)
target_link_libraries (FastOrderBook ${UUID_LIBRARIES})
target_include_directories (FastOrderBook PRIVATE ${UUID_INCLUDE_DIRS})

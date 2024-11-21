cmake_minimum_required(VERSION 3.30)

project(AdventOfCode2024 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB_RECURSE ALL_CXX_FILES "${CMAKE_SOURCE_DIR}/src/*.cxx")

# Add an executable for each .cxx file
foreach(CXX_FILE ${ALL_CXX_FILES})
    get_filename_component(EXECUTABLE_NAME ${CXX_FILE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${CXX_FILE})
endforeach()
cmake_minimum_required(VERSION 3.26)
project(dataStructures)

set(CMAKE_CXX_STANDARD 17)

FILE(GLOB_RECURSE CPPSources dataStructures/*.cpp)
FILE(GLOB_RECURSE HSources dataStructures/*.h)

include_directories(
        "${PROJECT_SOURCE_DIR}/dataStructures"
        "${PROJECT_SOURCE_DIR}/dataStructures/BigramStack"
        "${PROJECT_SOURCE_DIR}/dataStructures/Queue"
)


add_executable(dataStructures main.cpp Helpers.cpp Helpers.h ${CPPSources} ${HSources})


cmake_minimum_required(VERSION 2.8)
project(Metaballs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES
    "src/*.h"
    "src/*.cpp"
)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

add_executable(Metaballs ${SOURCE_FILES} )

find_package(SFML 2 COMPONENTS system window graphics REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(Metaballs ${SFML_LIBRARIES})

#set(SOURCE_FILES src/main.cpp)


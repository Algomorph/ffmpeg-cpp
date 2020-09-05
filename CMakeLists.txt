cmake_minimum_required(VERSION 3.5)
project(ffmpeg-cpp)

find_package(FFMPEG REQUIRED)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE ffmpeg-cpp-sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.cpp)
# appending all the folders so that visual studio can pick up.
list(APPEND FFMPEG_CPP_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/include 
                                    ${CMAKE_CURRENT_SOURCE_DIR}/include/Codecs 
                                    ${CMAKE_CURRENT_SOURCE_DIR}/include/Demuxing 
                                    ${CMAKE_CURRENT_SOURCE_DIR}/include/Info 
                                    ${CMAKE_CURRENT_SOURCE_DIR}/include/Muxing
                                    "${CMAKE_CURRENT_SOURCE_DIR}/include/Frame Sinks"
                                    "${CMAKE_CURRENT_SOURCE_DIR}/include/Input Sources")

include_directories(${FFMPEG_CPP_INCLUDE_DIRS})

add_library(ffmpeg-cpp ${ffmpeg-cpp-sources})
target_link_libraries(ffmpeg-cpp PUBLIC ${FFMPEG_LIBRARIES})
target_include_directories(ffmpeg-cpp PUBLIC ${FFMPEG_INCLUDE_DIRS} )

option(BUILD_EXAMPLES "Build example projects." FALSE)

add_subdirectory("examples")


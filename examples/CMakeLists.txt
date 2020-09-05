if(${BUILD_EXAMPLES})
    add_executable(decode_audio decode_audio.cpp)
    target_link_libraries(decode_audio ffmpeg-cpp)

    add_executable(decode_video decode_video.cpp)
    target_link_libraries(decode_video ffmpeg-cpp)
    
    add_executable(difference difference.cpp)
    target_link_libraries(difference ffmpeg-cpp)
    
    add_executable(encode_audio encode_audio.cpp)
    target_link_libraries(encode_audio ffmpeg-cpp)
    
    add_executable(encode_video encode_video.cpp)
    target_link_libraries(encode_video ffmpeg-cpp)
    
    add_executable(filtering_audio filtering_audio.cpp)
    target_link_libraries(filtering_audio ffmpeg-cpp)
    
    add_executable(filtering_video filtering_video.cpp)
    target_link_libraries(filtering_video ffmpeg-cpp)
    
    add_executable(print_info print_info.cpp)
    target_link_libraries(print_info ffmpeg-cpp)
    
    add_executable(remuxing remuxing.cpp)
    target_link_libraries(remuxing ffmpeg-cpp)

    file(GLOB_RECURSE demo-sources ${CMAKE_CURRENT_SOURCE_DIR}/demo/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/examples/demo/*.h)
    add_executable(demo ${demo-sources})
    target_link_libraries(demo ffmpeg-cpp)
endif()
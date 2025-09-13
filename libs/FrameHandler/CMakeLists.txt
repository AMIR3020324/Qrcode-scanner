add_library(FrameHandler FrameHandler.cpp)
target_include_directories(FrameHandler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(FrameHandler PRIVATE OpenCV::opencv_core OpenCV::opencv_videoio)
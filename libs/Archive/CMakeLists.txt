add_library(Archive Archive.cpp)
target_include_directories(Archive PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(Archive PRIVATE OpenCV::opencv_core OpenCV::opencv_imgcodecs nlohmann_json::nlohmann_json)
add_library(Archive Archive.cpp)

target_include_directories(Archive PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Archive PRIVATE ${OpenCV_LIBS} nlohmann_json::nlohmann_json)

add_library(UI UI.cpp)

target_include_directories(UI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(UI PRIVATE ${OpenCV_LIBS})

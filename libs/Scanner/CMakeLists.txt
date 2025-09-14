add_library(Scanner Scanner.cpp)

target_include_directories(Scanner PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(Scanner PRIVATE
    ${OpenCV_LIBS}
    ZXing::ZXing
)
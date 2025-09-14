cmake_minimum_required(VERSION 3.10)
project(AdvancedScanner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(ZXing CONFIG REQUIRED)

add_subdirectory(libs/FrameHandler)
add_subdirectory(libs/Scanner)
add_subdirectory(libs/UI)
add_subdirectory(libs/Archive)

add_executable(AdvancedScanner src/main.cpp)

target_link_libraries(AdvancedScanner PRIVATE
    FrameHandler
    Scanner
    UI
    Archive
    ${OpenCV_LIBS}
    nlohmann_json::nlohmann_json
    ZXing::ZXing
)
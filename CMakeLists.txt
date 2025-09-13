# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(AdvancedScanner)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages (dependencies)
find_package(OpenCV REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(ZXing-cpp CONFIG REQUIRED)

# Add all the library subdirectories
add_subdirectory(libs/FrameHandler)
add_subdirectory(libs/Scanner)
add_subdirectory(libs/UI)
add_subdirectory(libs/Archive)

# Add the main executable
add_executable(AdvancedScanner src/main.cpp)

# Link all compiled libraries and dependencies to the final executable
target_link_libraries(AdvancedScanner PRIVATE
    FrameHandler
    Scanner
    UI
    Archive
    OpenCV::opencv_core
    OpenCV::opencv_highgui
    OpenCV::opencv_imgproc
    OpenCV::opencv_imgcodecs
    OpenCV::opencv_videoio
    nlohmann_json::nlohmann_json
    ZXing-cpp::ZXing
)
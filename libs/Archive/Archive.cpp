#include "Archive.h"
#include <fstream>
#include <ctime>
#include <filesystem>
#include <iomanip>
#include <sstream>
#include <chrono>

namespace fs = std::filesystem;

void Archive::save(const cv::Mat& frame, const std::vector<std::string>& data) {
    std::string dir = "output";
    fs::create_directories(dir);

    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y%m%d_%H%M%S");
    std::string timeStr = ss.str();

    std::string imagePath = dir + "/frame_" + timeStr + ".jpg";
    std::string logPath = dir + "/log.json";

    cv::imwrite(imagePath, frame);

    nlohmann::json log_data = nlohmann::json::array();
    if (fs::exists(logPath)) {
        std::ifstream inFile(logPath);
        if (inFile.peek() != std::ifstream::traits_type::eof()) {
           inFile >> log_data;
        }
    }

    log_data.push_back({
        {"timestamp", timeStr},
        {"image_path", imagePath},
        {"decoded_data", data}
    });

    std::ofstream outFile(logPath);
    outFile << log_data.dump(4);
}
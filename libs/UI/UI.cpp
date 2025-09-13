#include "UI.h"

void UI::displayFrame(const cv::Mat& frame, const std::vector<std::string>& qrData) {
    cv::Mat canvas;
    frame.copyTo(canvas);

    const int baseY = 30;
    const int lineSpacing = 28;
    const int padding = 8;
    const int boxMargin = 5;
    cv::Scalar bgColor(0, 0, 0);
    cv::Scalar txtColor(0, 255, 255);
    cv::Scalar warnColor(0, 0, 255);
    int fontFace = cv::FONT_HERSHEY_DUPLEX;
    double fontScale = 0.55;
    int thickness = 1;

    if (qrData.empty()) {
        std::string warning = "[!] QR not found";
        int baseline = 0;
        auto textSize = cv::getTextSize(warning, fontFace, fontScale, thickness, &baseline);
        cv::Rect bgRect(cv::Point(boxMargin, baseY - textSize.height), cv::Size(textSize.width + 2 * padding, textSize.height + 2 * padding));
        cv::rectangle(canvas, bgRect, bgColor, cv::FILLED);
        cv::putText(canvas, warning, cv::Point(bgRect.x + padding, bgRect.y + textSize.height + padding / 2), fontFace, fontScale, warnColor, thickness);
    } else {
        for (size_t i = 0; i < qrData.size(); ++i) {
            std::string line = "QR#" + std::to_string(i + 1) + ": " + qrData[i];
            int baseline = 0;
            auto textSize = cv::getTextSize(line, fontFace, fontScale, thickness, &baseline);
            cv::Rect bgRect(cv::Point(boxMargin, baseY + i * lineSpacing - textSize.height), cv::Size(textSize.width + 2 * padding, textSize.height + 2 * padding));
            cv::rectangle(canvas, bgRect, bgColor, cv::FILLED);
            cv::putText(canvas, line, cv::Point(bgRect.x + padding, bgRect.y + textSize.height + padding / 2), fontFace, fontScale, txtColor, thickness);
        }
    }
    cv::imshow("Live Feed", canvas);
}
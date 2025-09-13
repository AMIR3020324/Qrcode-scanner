#include "FrameHandler.h"

FrameHandler::FrameHandler(int cameraIndex) {
    cap.open(cameraIndex);
}

FrameHandler::~FrameHandler() {
    if (cap.isOpened()) {
        cap.release();
    }
}

cv::Mat FrameHandler::getFrame() {
    cv::Mat frame;
    if (cap.isOpened()) {
        cap.read(frame);
    }
    return frame;
}

bool FrameHandler::isOpened() const {
    return cap.isOpened();
}
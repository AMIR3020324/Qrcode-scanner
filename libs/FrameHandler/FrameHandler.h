#ifndef FRAMEHANDLER_H
#define FRAMEHANDLER_H

#include <opencv2/opencv.hpp>

class FrameHandler {
public:
    FrameHandler(int cameraIndex = 0);
    ~FrameHandler();
    cv::Mat getFrame();
    bool isOpened() const;

private:
    cv::VideoCapture cap;
};

#endif // FRAMEHANDLER_H
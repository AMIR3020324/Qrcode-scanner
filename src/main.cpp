#include "../libs/FrameHandler/FrameHandler.h"
#include "../libs/Scanner/Scanner.h"
#include "../libs/UI/UI.h"
#include "../libs/Archive/Archive.h"
#include <iostream>

int main() {
    FrameHandler camera;
    if (!camera.isOpened()) {
        std::cerr << "Error: Could not open camera!" << std::endl;
        return -1;
    }

    Scanner scanner;
    UI ui;
    Archive archive;

    while (true) {
        auto frame = camera.getFrame();
        if (frame.empty()) {
            std::cerr << "Error: Could not grab frame." << std::endl;
            break;
        }

        auto results = scanner.scan(frame);
        ui.displayFrame(frame, results);
        
        if (!results.empty()) {
            archive.save(frame, results);
        }

        // Press 'ESC' (ASCII 27) or 'q' to exit
        int key = cv::waitKey(1);
        if (key == 27 || key == 'q') {
            break; 
        }
    }
    return 0;
}
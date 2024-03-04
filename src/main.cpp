#include <iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>

int main() {
    // Read the image
    cv::Mat image = cv::imread("7.png", cv::IMREAD_GRAYSCALE);

    // Check for invalid input
    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    cv::imwrite("processed_D-21_D-21.png", image);



    // OCR using Tesseract
    tesseract::TessBaseAPI tess;
    tess.Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);

    // Load image using Leptonica
    Pix* pixImage = pixRead("processed_D-21_D-21.png");

    // Set image for OCR
    tess.SetImage(pixImage);

    // Perform OCR
    char* outText = tess.GetUTF8Text();
    std::cout << "Extracted Text: " << outText << std::endl;

    // Release resources
    tess.End();
    delete[] outText;
    pixDestroy(&pixImage);

    return 0;
}

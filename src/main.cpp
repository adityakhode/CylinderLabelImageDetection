#include <iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>

int main() {
    // Read the image
    cv::Mat image = cv::imread("../testImages/1.jpg", cv::IMREAD_GRAYSCALE);

    // Check for invalid input
    if (image.empty()) {
        std::cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    cv::imwrite("Result_Img.jpg", image);



    // OCR using Tesseract
    tesseract::TessBaseAPI tess;
    tess.Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);

    // Load image using Leptonica
    Pix* pixImage = pixRead("Result_Img.jpg");

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

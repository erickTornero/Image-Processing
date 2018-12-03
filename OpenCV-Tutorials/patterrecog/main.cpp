#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <vector>

// ** Recognize patterns:
int main(int argc, char ** argv){
    cv::Mat pattern_row, pattern_border;
    // ** Load pattern in gray scale
    pattern_row = cv::imread("/home/erick/Documentos/MsCS/Images/opencv_prog/Tutorials/patterrecog/circleinc.png", CV_LOAD_IMAGE_COLOR);

    if(! pattern_row.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
    // ** Apply filter pattern
    
    cv::Canny(pattern_row, pattern_border,200, 300, 3);
    std::vector<cv::KeyPoint> keypoints;
    // ** Parameters of Single blob detectors to detect ellipses
    cv::SimpleBlobDetector::Params parameters;
    parameters.minThreshold = 10;
    parameters.maxThreshold = 200;
    cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(parameters);
    detector->detect(pattern_border, keypoints);

    // ** Print points detected
    for(size_t i = 0; i < keypoints.size(); i++){
      std::cout << i+1<<">";
      std::cout<<keypoints[i].pt<<"  - a> "<<keypoints[i].size<<std::endl;
      cv::circle(pattern_border, keypoints[i].pt, 2, cv::Scalar(255, 0, 0));
    }

    // ** Create Windows to show images:
    cv::namedWindow("RowPattern", CV_WINDOW_AUTOSIZE);
    // ** Show row Image:
    cv::imshow("RowPattern", pattern_row);
    // ** Create Windows to show Filtered image:
    cv::namedWindow("BorderFilteredImage", CV_WINDOW_AUTOSIZE);
    // **Show image filtered
    cv::imshow("BorderFilteredImage", pattern_border);

    // ** Wait for key press
    cv::waitKey(0);

    return 0;
}
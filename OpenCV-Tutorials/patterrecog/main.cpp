#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <vector>

void drawKeyPoints(std::vector<cv::KeyPoint> points, cv::Mat & img){
    for(auto it = points.begin(); it!=points.end(); it++){
        cv::circle(img, it->pt, 4, cv::Scalar(0, 0, 255), CV_FILLED);
    }
}
std::vector<cv::KeyPoint> getCorners(std::vector<cv::KeyPoint> points){
  int indxMinX = points.size()-1, indxMinY = 0, indxMaxX = 1, indxMaxY = 0;
  float tolerance = 0.03;
  for(int i = 2; i < points.size() - 1; i++){
    if(points[i].pt.x + tolerance> points[indxMaxX].pt.x)
        indxMaxX = i;
  }
  for(int i = points.size() - 2; i > 0; i--){
    if(points[i].pt.x - tolerance < points[indxMinX].pt.x)
        indxMinX = i;
  }
  std::vector<cv::KeyPoint> ans{points[indxMinX], points[indxMaxX], points[0], points[points.size()-1]};
  return ans;
}
// ** Recognize patterns:
int main(int argc, char ** argv){
    cv::Mat pattern_row, pattern_border;
    // ** Load pattern in gray scale
    pattern_row = cv::imread("pattern3.png", CV_LOAD_IMAGE_COLOR);

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

    std::vector<cv::KeyPoint> corners = getCorners(keypoints);
    // ** Print points detected
    for(size_t i = 0; i < keypoints.size(); i++){
      std::cout << i+1<<">";
      std::cout<<keypoints[i].pt<<"  - a> "<<keypoints[i].size<<std::endl;
      //cv::circle(pattern_row, keypoints[i].pt, 4, cv::Scalar(255, 0, 0), CV_FILLED);
      cv::putText(pattern_row, std::to_string(i+1), keypoints[i].pt, 4, 0.7, cv::Scalar(0, 255,0));
    }
    drawKeyPoints(corners, pattern_row);
    //cv::circle(pattern_row, corners[0].pt, 4, cv::Scalar(0, 0, 255), CV_FILLED);

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
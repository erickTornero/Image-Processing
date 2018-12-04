#include <opencv2/opencv.hpp>
#include "opencv2/highgui.hpp"
#include <iostream>
 
int main( int argc, char** argv ) {
  
  cv::Mat image;
  image = cv::imread("sample.png" , CV_LOAD_IMAGE_COLOR);
  
  cv::Mat grayIm = cv::imread("sample.png", CV_LOAD_IMAGE_GRAYSCALE);
  if(! image.data ) {
      std::cout <<  "Could not open or find the image" << std::endl ;
      return -1;
    }
  
  cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );
  cv::imshow( "Display window", image );

  cv::imshow("Display Gray scale", grayIm);

  cv::imwrite("outimg.jpg", grayIm);
  
  cv::waitKey(0);
  return 0;
}

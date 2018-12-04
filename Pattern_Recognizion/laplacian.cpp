#include "opencv2/opencv.hpp"
#include <opencv2/features2d.hpp>
#include <iostream>
#include <vector>

using namespace cv;
 
int main(){
 
  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  //VideoCapture cap(0);
  VideoCapture cap("../../../files/PadronAnillos_02.avi");
  // Check if camera opened successfully
  if(!cap.isOpened()){
    std::cout << "Error opening video stream or file" << std::endl;
    return -1;
  }
  
  cv::SimpleBlobDetector::Params params;
  params.minThreshold = 10;
  params.maxThreshold = 200;
  // Filter by Area.
	params.filterByArea = true;
	params.minArea = 100;
  // Filter by Circularity
  params.filterByCircularity = true;
  params.minCircularity = 0.8;
  // Filter by Convexity
  params.filterByConvexity = true;
  params.minConvexity = 0.9;
  // Filter by Inertia
  params.filterByInertia = true;
  params.minInertiaRatio = 0.01;

  while(1){
 
    Mat frame;
    Mat dest_gray, border_gray, laplacian, src;
    
    // Capture frame-by-frame
    cap >> frame;
    //GaussianBlur( frame, src, Size(3, 3), 0, 0, BORDER_DEFAULT );
    cv::cvtColor(frame, dest_gray, cv::COLOR_BGR2GRAY);
    //imshow( "Black", dest_gray );
    //cv::Canny( dest_gray, border_gray, 200, 300, 3 );
    
    cv::Canny( dest_gray, border_gray, 200, 300, 3 );
    cv::Laplacian( border_gray, laplacian, CV_8U );
    imshow( "Canny", laplacian );
    std::vector<cv::KeyPoint> keypoints;
    
    cv::Ptr<cv::SimpleBlobDetector> detector = cv::SimpleBlobDetector::create(params);
    detector->detect(laplacian, keypoints);
    // If the frame is empty, break immediately
    Mat drawI = border_gray.clone();

    //std::cout << "KeyPoint size = " << keypoints.size() << std::endl;
    for(size_t i = 0; i < keypoints.size(); i++){
        cv::circle(frame, keypoints[i].pt, 5, cv::Scalar(180,180,0), 3);
        //std::cout << i << " KeyPoint = " << keypoints[i].pt << std::endl;
        cv::putText(frame, std::to_string(i), keypoints[i].pt, cv::FONT_HERSHEY_SIMPLEX , 0.5, (255,255,255), 1, cv::LINE_AA);
    }
    if (frame.empty())
      break;
 
    // Display the resulting frame
    imshow( "Frame", frame );
 
    // Press  ESC on keyboard to exit
    char c=(char)waitKey(25);
    if(c==27)
      break;
  }
  
  // When everything done, release the video capture object
  cap.release();
 
  // Closes all the frames
  destroyAllWindows();
     
  return 0;
}

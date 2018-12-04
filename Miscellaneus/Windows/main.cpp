# include "opencv2/opencv.hpp"

int main(){
    cv::Mat img1 = cv::imread("cat.jpg", CV_LOAD_IMAGE_UNCHANGED);
    cv::Mat img2 = cv::imread("cat.jpg",CV_LOAD_IMAGE_GRAYSCALE);

    cv::namedWindow("MyWin", CV_WINDOW_FREERATIO);

    cv::namedWindow("Fixed", CV_WINDOW_AUTOSIZE);

    cv::imshow("MyWin", img1);
    cv::imshow("Fixed", img2);

    cv::resizeWindow("MyWin", img1.cols/2, img2.rows/2);
    cv::resizeWindow("Fixed", img2.cols/2, img2.rows/2);

    cv::moveWindow("Fixed", 2000, 1080);
    cv::waitKey();
}
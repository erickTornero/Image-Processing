# include <opencv2/opencv.hpp>
# include <stdint.h>
int main(){

    cv::Mat img = cv::imread("cat.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    cv::Mat mod = cv::imread("cat.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    for(int row = 0; row < img.rows; row++){
        for(int col = 0; col < img.cols; col++){
            mod.at<uint8_t>(row, col) = mod.at<uint8_t>(row, col)*0.5f;
        }
    }
    //cv::namedWindow("Or", CV_Fixed)
    cv::imshow("Orig", img);
    cv::imshow("Mod", mod);
    cv::waitKey();
}
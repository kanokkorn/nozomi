// standard
#include <iostream>

// opencv
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

// cvui
#define CVUI_IMPLEMENTATION
#include "lib/cvui.h"
#define WINDOW_NAME "canny edge"

int show_canny(cv::Mat);

int main(void) {
  std::cout << "Nozooomi!" << std::endl;
  std::cout << "using OpenCV version "<< CV_VERSION << std::endl;
  // put sample.jpg in build folder
  cv::Mat image =  cv::imread("./sample.jpg");
  cv::Mat frame = image.clone();
  bool apply_canny = false;
  bool apply_blur = false;
  if (image.empty()){
    std::cout << "Could not load image!\nPut an image in build folder and rename to sample.jpg" << std::endl;
    return -1;
  }
  cvui::init(WINDOW_NAME);
  while(true){
    if(apply_canny){
      cv::cvtColor(image, frame, cv::COLOR_BGR2GRAY);
      cv::Canny(frame, frame, 100, 200, 3);
    } else {
      image.copyTo(frame);
    }
    cvui::checkbox(frame, 15, 80, "Use canny", &apply_canny);
    cvui::update();
    cv::imshow(WINDOW_NAME, frame);
    if(cv::waitKey(1) == 27){
      std::cout << "exiting..." << std::endl;
      break;
    }
  }
  return 0;
}

int show_canny(cv::Mat image_input){
  cv::Mat image_gray;
  cv::Mat dst, detected_edges;
  cv::cvtColor(image_input, image_gray, cv::COLOR_BGR2GRAY);
  const int lowThreshold = 100;
  const int max_lowThreshold = 200;
  const int ratio = 3;
  const int kernel_size = 3;
  const char* window_name = "Edged";
  cv::blur(image_gray, detected_edges, cv::Size(3, 3));
  cv::Canny(detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size);
  dst = cv::Scalar::all(0);
  image_input.copyTo(dst, detected_edges);
  cv::imshow(window_name, dst);
  return 0;
}

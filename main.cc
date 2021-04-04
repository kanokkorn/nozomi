/* standard */
#include <iostream>
#include <cstdlib>

/* opencv */
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core/mat.hpp>

/* function declaration */
    /* basic stuff */
int canny_basic(cv::Mat);
int blur_basic(cv::Mat);

    /* opencl stuff */
int canny_ocl(cv::UMat);
int blur_ocl(cv::UMat);
int display_matrix_ocl(cv::UMat);
int cascade_ocl(cv::UMat);

    /* CUDA stuff */
      /* TBD */


<<<<<<< HEAD:main.cc
int main(int argc, char** argv) {
  std::cout << "Nozooomi!" << std::endl;
  std::cout << "using OpenCV version "<< CV_VERSION << std::endl;
  if (argv[1] == NULL) {
    std::cout << "no image input! aborting...\n";
    exit(1);
  }
  cv::Mat image =  cv::imread(argv[1]);
  cv::Mat frame = image.clone();
  bool apply_canny = false;
  bool apply_blur = false;
  if (image.empty()){
    std::cout << "Could not load image!\n" << std::endl;
=======
int main(void) {
  std::cout << "Nozomi is running...\n";
  std::cout << "using OpenCV version "<< CV_VERSION << "\n";
  cv::UMat image;
  cv::imread("./sample.jpg").copyTo(image);
  if (image.empty()) {
    std::cout << "Could not load image!\nPut an image in build folder and rename to sample.jpg\n";
>>>>>>> b0aa5b624e1e956e290e4d318eeeea6f3e149f50:main.cpp
    return -1;
  } 
  display_matrix_ocl(image);
  /* exit when press q */
  if (cv::waitKey(0) == 113) {
    std::cout << "exiting...\n";
    cv::destroyAllWindows();
  }
  return 0;
}

<<<<<<< HEAD:main.cc
int read_camera(void){
  cv::Mat frame;
  cv::VideoCapture cap;
  int deviceID = 0;
  int apiID = cv::CAP_ANY;
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
=======
int canny_basic(cv::Mat) {
  return 0;
}

int blur_basic(cv::Mat) {
  return 0;
}

/* display image as matrix in terminal */
int display_matrix_ocl(cv::UMat image) {
  std::cout << image << "\n";
  return 0;
}

/* apply blur to image with 25x25 kernel size */
int blur_ocl(cv::UMat image) {
  cv::GaussianBlur(image, image, cv::Size(25, 25), 0);
  cv::imshow("blur opencl", image);
  return 0;
}

/* edge detection with canny */
int canny_ocl(cv::UMat image) {
  cv::UMat gray;
  cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
  cv::Canny(gray, gray, 100, 200, 3);
  cv::imshow("canny opencl", gray);
  return 0;
}

/* HAAR cascade with opencl */
int cascade_ocl(cv::UMat image) {
>>>>>>> b0aa5b624e1e956e290e4d318eeeea6f3e149f50:main.cpp
  return 0;
}

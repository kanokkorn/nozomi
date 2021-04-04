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
void canny_basic(cv::Mat);
void blur_basic(cv::Mat);

    /* opencl stuff */
void canny_ocl(cv::UMat);
void blur_ocl(cv::UMat);
void display_matrix_ocl(cv::UMat);
void cascade_ocl(cv::UMat);

    /* CUDA stuff */
      /* TBD */


int main(int argc, char** argv) {
  std::cout << "Nozooomi!" << std::endl;
  std::cout << "using OpenCV version "<< CV_VERSION << std::endl;
  if (argv[1] == NULL) {
    std::cout << "no image input! aborting...\n";
    exit(1);
  }
  cv::UMat image;
  cv::imread(argv[1], 1).copyTo(image);
  bool apply_canny = false;
  bool apply_blur = false;
  if (image.empty()){
    std::cout << "Could not load image!\n" << std::endl;
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

void read_camera(void){
  cv::Mat frame;
  cv::VideoCapture cap;
  int deviceID = 0;
  int apiID = cv::CAP_ANY;
}

void show_canny(cv::Mat image_input){
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
}

void display_matrix_ocl(cv::UMat img) {
  std::cout << img;
}

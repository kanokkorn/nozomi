/* standard */
#include <iostream>

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


int main(void) {
  std::cout << "Nozomi is running...\n";
  std::cout << "using OpenCV version "<< CV_VERSION << "\n";
  cv::UMat image;
  cv::imread("./sample.jpg").copyTo(image);
  if (image.empty()) {
    std::cout << "Could not load image!\nPut an image in build folder and rename to sample.jpg\n";
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
  return 0;
}

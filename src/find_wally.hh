#ifndef _FOUND_WALLY_FIND_WALLY_H_
#define _FOUND_WALLY_FIND_WALLY_H_

#include <opencv2/opencv.hpp>

class FindWally {
public:
  FindWally();
  static const int RED = 2;
  static const int GREEN = 1;
  static const int BLUE = 0;
  const static std::string WINDOW_NAME;
  cv::Mat getImage();
  void setImage(const std::string &filepath);
  void setImage(const cv::Mat &image);
  void findWally();
private:
  cv::Mat src;
  cv::Mat dst;
};

#endif //_FOUND_WALLY_FIND_WALLY_H_

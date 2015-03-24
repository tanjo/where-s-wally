#include "find_wally.hh"
#include <vector>

FindWally::FindWally() {
}

const std::string FindWally::WINDOW_NAME = [] {
  const std::string str = "Where's Wally";
  return str;
}();

cv::Mat FindWally::getImage() {
  return this->dst.clone();
}

void FindWally::setImage(const cv::Mat &image) {
  this->src = image;
  this->dst = this->src.clone();
}

void FindWally::setImage(const std::string &filepath) {
  this->setImage(cv::imread(filepath, cv::IMREAD_COLOR));
}

void FindWally::findWally() {
  cv::Mat tmp = cv::imread("img/template.png", cv::IMREAD_COLOR);

  cv::matchTemplate(this->src, tmp, this->dst, cv::TM_CCOEFF);

  double min_val, max_val;
  cv::Point min_loc, max_loc;
  cv::minMaxLoc(this->dst, &min_val, &max_val, &min_loc, &max_loc);

  this->dst = this->src.clone();
  cv::rectangle(this->dst, max_loc, cv::Point(max_loc.x + tmp.cols, max_loc.y + tmp.rows), CV_RGB(0, 255, 0), 2);
}
#include <iostream>
#include "src/find_wally.hh"

int main() {
  const std::string IMAGE_FILE = "img/wally.jpg";

  FindWally *fw = new FindWally();

  fw->setImage(IMAGE_FILE);

  fw->findWally();

  cv::imshow(fw->WINDOW_NAME, fw->getImage());
  cv::waitKey(0);

  delete fw;

  return 0;
}

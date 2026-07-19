
#ifndef PREPROCESSOR_H
#define PREPROCESSOR_H

#include <opencv2/opencv.hpp>
#include <vector>

class Preprocessor
{
public:
std::vector<cv::Mat> preprocess(
const std::vector<cv::Mat>&images);
};

#endif

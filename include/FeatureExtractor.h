#ifndef FEATUREEXTRACTOR_H
#define FEATUREEXTRACTOR_H

#include <opencv2/opencv.hpp>
#include <vector>

class FeatureExtractor
{
public:
std::vector<std::vector<float>> extractFeatures(
const std::vector<cv::Mat>& images);

std::vector<std::vector<float>> extractFeaturesParallel(
    const std::vector<cv::Mat>& images);

};

#endif

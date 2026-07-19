#include "../include/FeatureExtractor.h"

#include <omp.h>
#include <vector>

// Sequential Feature Extraction
std::vector<std::vector<float>>
FeatureExtractor::extractFeatures(
const std::vector<cv::Mat>& images)
{
std::vector<std::vector<float>> allFeatures;

cv::HOGDescriptor hog(
    cv::Size(128, 128),
    cv::Size(16,16),
    cv::Size(8,8),
    cv::Size(8,8),
    9);

for (const auto& image : images)
{
    std::vector<float> descriptors;

    hog.compute(image, descriptors);

    allFeatures.push_back(descriptors);
}

return allFeatures;
    
}

// Parallel Feature Extraction
std::vector<std::vector<float>>
FeatureExtractor::extractFeaturesParallel(
const std::vector<cv::Mat>& images)
{
std::vector<std::vector<float>>
allFeatures(images.size());

#pragma omp parallel for
for (int i = 0; i < static_cast<int>(images.size()); ++i)
{
    cv::HOGDescriptor hog(
        cv::Size(128, 128),
        cv::Size(16,16),
        cv::Size(8,8),
        cv::Size(8,8),
        9);

    std::vector<float> descriptors;

    hog.compute(images[i], descriptors);

    allFeatures[i] = descriptors;
}

return allFeatures;

}

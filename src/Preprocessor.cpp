#include "../include/Preprocessor.h"

#include <omp.h>

std::vector<cv::Mat> Preprocessor::preprocess(
const std::vector<cv::Mat>& images)
{
std::vector<cv::Mat>
processedImages(images.size());

#pragma omp parallel for
for (int i = 0; i < static_cast<int>(images.size()); ++i)
{
    cv::Mat resized;
    cv::Mat gray;

    cv::resize(
        images[i],
        resized,
        cv::Size(128,128));

    cv::cvtColor(
        resized,
        gray,
        cv::COLOR_BGR2GRAY);

    processedImages[i] = gray;
}

return processedImages;

}

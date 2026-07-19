#include "../include/ImageLoader.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

ImageLoader::ImageLoader(const std::string& datasetPath)
: datasetPath(datasetPath)
{
}

void ImageLoader::loadImages()
{
images.clear();
labels.clear();

for (const auto& category : fs::directory_iterator(datasetPath))
{
    if (!category.is_directory())
        continue;

    std::string label =
        category.path().filename().string();

    for (const auto& imageFile :
         fs::directory_iterator(category.path()))
    {
        cv::Mat image =
            cv::imread(imageFile.path().string());

        if (!image.empty())
        {
            images.push_back(image);
            labels.push_back(label);
        }
    }
}

std::cout << "Loaded "
          << images.size()
          << " images."
          << std::endl;

}

std::vector<cv::Mat> ImageLoader::getImages() const
{
return images;
}

std::vector<std::string> ImageLoader::getLabels() const
{
return labels;
}


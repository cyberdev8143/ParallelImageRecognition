#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>

class ImageLoader
{
public:
ImageLoader(const std::string& datasetPath);

void loadImages();

std::vector<cv::Mat> getImages() const;
std::vector<std::string> getLabels() const;


private:
std::string datasetPath;

std::vector<cv::Mat> images;
std::vector<std::string> labels;

};

#endif

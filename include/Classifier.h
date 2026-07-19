#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <string>
#include <vector>

class Classifier
{
public:
void train(
const std::vector<std::vector<float>>& features,
const std::vector<std::string>& labels);

std::string predict(
    const std::vector<float>& sample,
    int k = 5);

private:
std::vector<std::vector<float>> trainingFeatures;
std::vector<std::string> trainingLabels;
};

#endif

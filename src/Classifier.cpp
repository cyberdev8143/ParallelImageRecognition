#include "../include/Classifier.h"

#include <algorithm>
#include <cmath>
#include <map>
#include <utility>

void Classifier::train(
const std::vector<std::vector<float>>& features,
const std::vector<std::string>& labels)
{
trainingFeatures = features;
trainingLabels = labels;
}

std::string Classifier::predict(
const std::vector<float>& sample,
int k)
{
std::vector<std::pair<double, std::string>>
distances;

for (size_t i = 0;
     i < trainingFeatures.size();
     ++i)
{
    double distance = 0.0;

    for (size_t j = 0;
         j < sample.size();
         ++j)
    {
        double diff =
            sample[j] -
            trainingFeatures[i][j];

        distance += diff * diff;
    }

    distance = std::sqrt(distance);

    distances.push_back(
        {distance, trainingLabels[i]});
}

std::sort(
    distances.begin(),
    distances.end());

std::map<std::string, int> votes;

for (int i = 0; i < k; ++i)
{
    votes[distances[i].second]++;
}

std::string bestLabel;
int maxVotes = 0;

for (const auto& vote : votes)
{
    if (vote.second > maxVotes)
    {
        maxVotes = vote.second;
        bestLabel = vote.first;
    }
}

return bestLabel;

}

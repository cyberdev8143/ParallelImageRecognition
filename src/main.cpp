#include <iostream>
#include <fstream>
#include <vector>
#include <omp.h>

#include "../include/ImageLoader.h"
#include "../include/Preprocessor.h"
#include "../include/FeatureExtractor.h"
#include "../include/Classifier.h"
#include "../include/PerformanceMonitor.h"

int main()
{
    // Set number of threads
    omp_set_num_threads(4);

    std::cout << "Using "
              << omp_get_max_threads()
              << " threads."
              << std::endl;

    // Load dataset
    ImageLoader loader("../dataset");

    loader.loadImages();

    auto images = loader.getImages();
    auto labels = loader.getLabels();

    // Preprocess images
    Preprocessor preprocessor;

    auto processedImages =
        preprocessor.preprocess(images);

    std::cout << "Preprocessed "
              << processedImages.size()
              << " images."
              << std::endl;

    // Feature extraction
    FeatureExtractor extractor;

    // Sequential timing
    PerformanceMonitor seqMonitor;

    seqMonitor.start();

    auto features =
        extractor.extractFeatures(
            processedImages);

    seqMonitor.stop();

    std::cout << "Extracted features from "
              << features.size()
              << " images."
              << std::endl;

    std::cout
        << "Sequential Feature Extraction Time: "
        << seqMonitor.getExecutionTime()
        << " seconds"
        << std::endl;

    // Parallel timing
    PerformanceMonitor parMonitor;

    parMonitor.start();

    auto parallelFeatures =
        extractor.extractFeaturesParallel(
            processedImages);

    parMonitor.stop();

    std::cout
        << "Parallel Feature Extraction Time: "
        << parMonitor.getExecutionTime()
        << " seconds"
        << std::endl;

    // Compute speedup and efficiency
    double speedup =
        seqMonitor.getExecutionTime()
        /
        parMonitor.getExecutionTime();

    double efficiency =
        speedup
        /
        omp_get_max_threads();

    std::cout
        << "Speedup: "
        << speedup
        << std::endl;

    std::cout
        << "Efficiency: "
        << efficiency * 100
        << "%"
        << std::endl;

    // Save results to CSV
    std::ofstream file(
        "results.csv",
        std::ios::app);

    file
        << omp_get_max_threads()
        << ","
        << seqMonitor.getExecutionTime()
        << ","
        << parMonitor.getExecutionTime()
        << ","
        << speedup
        << ","
        << efficiency * 100
        << std::endl;

    file.close();

    // Train classifier
    Classifier classifier;

    classifier.train(features, labels);

    // Ask user for image path
    std::string imagePath;

    std::cout
        << "\nEnter image path to test: ";

    std::cin >> imagePath;

    // Load test image
    cv::Mat testImage =
        cv::imread(imagePath);

    if (testImage.empty())
    {
        std::cout
            << "Error: Could not load image!"
            << std::endl;

        return -1;
    }

    // Preprocess test image
    cv::resize(testImage,
               testImage,
               cv::Size(128, 128));

    cv::cvtColor(testImage,
                 testImage,
                 cv::COLOR_BGR2GRAY);

    // Put image in vector
    std::vector<cv::Mat> testImages;

    testImages.push_back(testImage);

    // Extract features
    auto testFeatures =
        extractor.extractFeatures(
            testImages);

    // Predict class
    std::string prediction =
        classifier.predict(
            testFeatures[0]);

    std::cout
        << "\nPrediction: "
        << prediction
        << std::endl;

    return 0;
}

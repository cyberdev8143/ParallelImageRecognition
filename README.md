# Parallelized Image Recognition System Using Multicore Programming

## Overview

This project implements a **parallelized image recognition system** in **C++** using **OpenMP** for multicore processing and **OpenCV** for image processing. The objective is to demonstrate how parallel programming can significantly reduce image feature extraction time while maintaining a functional image classification pipeline.

The implementation compares **sequential** and **parallel** execution of Histogram of Oriented Gradients (HOG) feature extraction and evaluates the performance using execution time, speedup, and parallel efficiency.

This project was developed as part of the **Multicore Programming** course in the **Master of Software Engineering** program at the **University of Europe for Applied Sciences**.

---

# Features

- Parallel image preprocessing using OpenMP
- Sequential and parallel HOG feature extraction
- K-Nearest Neighbour (KNN) image classification
- Performance benchmarking
- Speedup and efficiency calculation
- CSV logging of performance results
- Interactive image prediction from user input

---

# Technologies Used

- C++17
- OpenMP
- OpenCV 4.x
- CMake
- Apple Clang / GCC

---

# System Architecture

The system consists of the following stages:

<img width="1536" height="1024" alt="system_architecture" src="https://github.com/user-attachments/assets/878b707c-8fac-4196-9b81-fbcff2a07829" />


```
Dataset
   │
   ▼
Image Loader
   │
   ▼
Image Preprocessing
   │
   ▼
Feature Extraction (HOG)
   │
   ├───────────────┐
   │               │
Sequential     Parallel (OpenMP)
   │               │
   └───────────────┘
           │
           ▼
      Feature Vectors
           │
           ▼
    KNN Classification
           │
           ▼
 Predicted Image Class
           │
           ▼
 Performance Evaluation
```

---

# Project Structure

```
Parallelized-Image-Recognition-System/
│
├── README.md
├── LICENSE
├── CMakeLists.txt
├── references.bib
├── results.csv
│
├── include/
│   ├── Classifier.h
│   ├── FeatureExtractor.h
│   ├── ImageLoader.h
│   ├── PerformanceMonitor.h
│   └── Preprocessor.h
│
├── src/
│   ├── main.cpp
│   ├── Classifier.cpp
│   ├── FeatureExtractor.cpp
│   ├── ImageLoader.cpp
│   ├── PerformanceMonitor.cpp
│   └── Preprocessor.cpp
│
├── dataset/
│
├── figures/
│
├── report/
│
└── presentation/
```

---

# Dataset

The system was evaluated using a four-class image dataset consisting of:

- Cat
- Dog
- Automobile
- Airplane

Images are organized into folders where each folder name represents the corresponding class label.

Example:

```
dataset/

├── cat/
├── dog/
├── automobile/
└── airplane/
```

---

# Software Requirements

- macOS or Linux
- CMake 3.15+
- OpenCV 4.x
- OpenMP
- C++17 Compatible Compiler

---

# Build Instructions

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/Parallelized-Image-Recognition-System.git
```

Enter the project folder:

```bash
cd Parallelized-Image-Recognition-System
```

Create a build directory:

```bash
mkdir build
cd build
```

Generate the build files:

```bash
cmake ..
```

Compile the project:

```bash
make
```

---

# Running the Program

Execute the program from the build directory:

```bash
./ParallelImageRecognition
```

The application will:

- Load the dataset
- Preprocess all images
- Perform sequential feature extraction
- Perform parallel feature extraction
- Calculate speedup and efficiency
- Train the KNN classifier
- Prompt the user to enter an image path for prediction

Example:

```
Enter image path to test:

../test_images/car.jpg
```

Output:

```
Prediction: automobile
```

---

# Reproducing the Experimental Results

The performance evaluation presented in the report can be reproduced by changing the number of OpenMP threads in `main.cpp`.

Example:

```cpp
omp_set_num_threads(1);
```

Repeat the experiment for:

```cpp
omp_set_num_threads(2);
omp_set_num_threads(4);
omp_set_num_threads(8);
```

For each execution, the application records:

- Sequential execution time
- Parallel execution time
- Speedup
- Parallel efficiency

The results are automatically stored in:

```
results.csv
```

---

# Performance Metrics

The following metrics were used to evaluate the system:

- Sequential Execution Time
- Parallel Execution Time
- Speedup
- Parallel Efficiency
- Classification Accuracy

Example results:

| Threads | Sequential (s) | Parallel (s) | Speedup | Efficiency |
|----------|---------------:|-------------:|---------:|-----------:|
| 1 | 0.977 | 0.969 | 1.01 | 100.7% |
| 2 | 0.999 | 0.530 | 1.88 | 94.1% |
| 4 | 0.988 | 0.281 | 3.52 | 88.0% |
| 8 | 0.978 | 0.216 | 4.54 | 56.7% |

---

# Design Choices

## Why C++?

C++ provides high performance, efficient memory management, and low-level hardware access, making it well suited for high-performance multicore applications.

## Why OpenMP?

OpenMP was selected because it provides an efficient shared-memory parallel programming model with significantly lower implementation complexity than manual thread management using POSIX Threads. The target platform is a multicore shared-memory system rather than a distributed-memory cluster, making OpenMP an appropriate choice.

## Why HOG?

Histogram of Oriented Gradients (HOG) provides computationally efficient handcrafted feature extraction while maintaining good descriptive capability for object recognition tasks.

## Why KNN?

K-Nearest Neighbour (KNN) was selected because it is simple to implement, requires no complex training phase, and integrates naturally with HOG feature vectors, allowing the project to focus on evaluating multicore performance.

---

# Limitations

The current implementation has several limitations:

- Classification is limited to four image classes.
- HOG descriptors provide lower recognition accuracy than modern deep learning methods.
- The implementation targets a single shared-memory multicore computer.
- GPU acceleration is not implemented.
- Performance was evaluated on a single hardware platform.

---

# Future Work

Possible future improvements include:

- Deep learning based image classification
- CUDA GPU acceleration
- Distributed processing using MPI
- Larger benchmark datasets
- Hybrid CPU-GPU parallel processing

---

# Academic Integrity

Artificial Intelligence (AI) tools, including OpenAI's ChatGPT, were used during software development for debugging assistance, code review, documentation refinement, and LaTeX formatting. All implementation decisions, experimental evaluation, testing, and final verification were performed and validated by the project author.

---

# References

Please refer to **references.bib** and the accompanying project report for the complete list of academic references.

---

# Author

**Yonlonfun Gbemavo**

Master of Software Engineering

University of Europe for Applied Sciences

---

# License

This project is released under the MIT License.<img width="1536" height="1024" alt="system_architecture" src="https://github.com/user-attachments/assets/226b4a15-caa7-44af-bb45-c9d847e946cf" />

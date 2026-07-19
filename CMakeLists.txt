cmake_minimum_required(VERSION 3.16)

project(ParallelImageRecognition)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenCV REQUIRED)

# macOS Apple Silicon OpenMP settings

if(APPLE)
include_directories(/opt/homebrew/opt/libomp/include)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Xpreprocessor -fopenmp")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Xpreprocessor -fopenmp")

set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp")
set(OpenMP_CXX_FLAGS "-Xpreprocessor -fopenmp")
set(OpenMP_C_LIB_NAMES "omp")
set(OpenMP_CXX_LIB_NAMES "omp")
set(OpenMP_omp_LIBRARY "/opt/homebrew/opt/libomp/lib/libomp.dylib")


endif()

find_package(OpenMP REQUIRED)

include_directories(
include
${OpenCV_INCLUDE_DIRS}
)

add_executable(ParallelImageRecognition
src/main.cpp
src/ImageLoader.cpp
src/Preprocessor.cpp
src/FeatureExtractor.cpp
src/Classifier.cpp
src/SequentialSystem.cpp
src/ParallelSystem.cpp
src/PerformanceMonitor.cpp
)

target_link_libraries(
ParallelImageRecognition
${OpenCV_LIBS}
OpenMP::OpenMP_CXX
)

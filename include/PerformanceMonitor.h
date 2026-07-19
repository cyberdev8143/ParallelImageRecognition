#ifndef PERFORMANCEMONITOR_H
#define PERFORMANCEMONITOR_H

#include <chrono>

class PerformanceMonitor
{
public:
void start();

void stop();

double getExecutionTime() const;

private:
std::chrono::high_resolution_clock::time_point startTime;
std::chrono::high_resolution_clock::time_point endTime;
};

#endif


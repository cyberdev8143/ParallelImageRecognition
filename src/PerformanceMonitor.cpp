#include "../include/PerformanceMonitor.h"

void PerformanceMonitor::start()
{
startTime =
std::chrono::high_resolution_clock::now();
}

void PerformanceMonitor::stop()
{
endTime =
std::chrono::high_resolution_clock::now();
}

double PerformanceMonitor::getExecutionTime() const
{
std::chrono::duration<double> duration =
endTime - startTime;

return duration.count();

}


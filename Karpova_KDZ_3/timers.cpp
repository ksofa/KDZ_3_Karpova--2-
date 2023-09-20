#include <chrono>
#include <vector>
#include "timers.h"
#include "algorithms.h"

auto clock_start = std::chrono::high_resolution_clock::now();
auto elapsed = std::chrono::high_resolution_clock::now() - clock_start;
int64_t nanoseconds;

int64_t getDijkstraPriorityQueueTime(const std::vector<std::vector<int>> &g, int start, int end) {
    clock_start = std::chrono::high_resolution_clock::now();
    dijkstraPriorityQueue(g, start, end);
    elapsed = std::chrono::high_resolution_clock::now() - clock_start;
    nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    return nanoseconds;
}

int64_t getDijkstraVectorTime(const std::vector<std::vector<int>> &g, int start, int end) {
    clock_start = std::chrono::high_resolution_clock::now();
    dijkstraVector(g, start, end);
    elapsed = std::chrono::high_resolution_clock::now() - clock_start;
    nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    return nanoseconds;
}

int64_t getFloydWarshallTime(const std::vector<std::vector<int>> &g, int start, int end) {
    clock_start = std::chrono::high_resolution_clock::now();
    floydWarshall(g, start, end);
    elapsed = std::chrono::high_resolution_clock::now() - clock_start;
    nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    return nanoseconds;
}

int64_t getFordBellmanTime(const std::vector<std::vector<int>> &g, int start, int end) {
    clock_start = std::chrono::high_resolution_clock::now();
    fordBellman(g, start, end);
    elapsed = std::chrono::high_resolution_clock::now() - clock_start;
    nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed).count();

    return nanoseconds;
}
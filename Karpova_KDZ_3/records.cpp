#include <vector>
#include <string>
#include <chrono>
#include "records.h"
#include "algorithms.h"
#include "writer.h"
#include "timers.h"

void recordDijkstraPriorityQueue(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        std::string name) {

    int64_t sum = 0;
    int size = g.size();
    int runsNum = 5;
    name += " dijkstra queue";

    for (int i = 0; i < runsNum; ++i) {
        sum += getDijkstraPriorityQueueTime(g, start, end) / runsNum;
    }

    writeInfo(file, name, sum, size, numEdges);
}

void recordDijkstraVector(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        std::string name) {

    int64_t sum = 0;
    int size = g.size();
    int runsNum = 5;
    name += " dijkstra vector";

    for (int i = 0; i < runsNum; ++i) {
        sum += getDijkstraVectorTime(g, start, end) / runsNum;
    }

    writeInfo(file, name, sum, size, numEdges);
}

void recordFord(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        std::string name) {

    int64_t sum = 0;
    int size = g.size();
    int runsNum = 5;
    name += " ford";

    for (int i = 0; i < runsNum; ++i) {
        sum += getFordBellmanTime(g, start, end) / runsNum;
    }

    writeInfo(file, name, sum, size, numEdges);
}

void recordFloyd(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        std::string name) {

    int64_t sum = 0;
    int size = g.size();
    int runsNum = 5;
    name += " floyd";

    for (int i = 0; i < runsNum; ++i) {
        sum += getFloydWarshallTime(g, start, end) / runsNum;
    }

    writeInfo(file, name, sum, size, numEdges);
}
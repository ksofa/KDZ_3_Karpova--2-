#ifndef KDZ_3_RECORDS_H
#define KDZ_3_RECORDS_H

void recordDijkstraPriorityQueue(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        std::string name);

void recordDijkstraVector(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        std::string name);

void recordFloyd(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        std::string name);

void recordFord(
        std::ofstream &file,
        const std::vector<std::vector<int>> &g,
        int start,
        int end,
        int numEdges,
        std::string name);

#endif //KDZ_3_RECORDS_H

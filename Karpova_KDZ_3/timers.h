#ifndef KDZ_3_TIMERS_H
#define KDZ_3_TIMERS_H

int64_t getDijkstraPriorityQueueTime(const std::vector<std::vector<int>> &g, int start, int end);

int64_t getDijkstraVectorTime(const std::vector<std::vector<int>> &g, int start, int end);

int64_t getFloydWarshallTime(const std::vector<std::vector<int>> &g, int start, int end);

int64_t getFordBellmanTime(const std::vector<std::vector<int>> &g, int start, int end);

#endif //KDZ_3_TIMERS_H

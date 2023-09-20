#ifndef KDZ_3_ALGORITHMS_H
#define KDZ_3_ALGORITHMS_H

#include <vector>

// Алгоритм Дейкстры через очередь с приортитетом
int dijkstraPriorityQueue(const std::vector<std::vector<int>> &g, int start, int end);

// Алгоритм Дейкстры через вектор
int dijkstraVector(const std::vector<std::vector<int>> &g, int start, int end);

// Алгоритм Флойда-Уоршела
int floydWarshall(const std::vector<std::vector<int>> &g, int start, int end);

// Алгоритм Форда-Беллмана
int fordBellman(const std::vector<std::vector<int>> &g, int start, int end);

#endif //KDZ_3_ALGORITHMS_H
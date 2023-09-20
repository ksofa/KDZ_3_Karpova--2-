#include "algorithms.h"
#include <vector>
#include <limits>
#include <queue>

// Алгоритм Дейкстры
int dijkstraPriorityQueue(const std::vector<std::vector<int>> &g, int start, int end) {
    auto n = g.size();
    std::vector<int> dist(n, std::numeric_limits<int>::max());
    std::vector<bool> visited(n, false);
    dist[start] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push(std::make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (g[u][v] != 0) {
                int weight = g[u][v];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(std::make_pair(dist[v], v));
                }
            }
        }
    }

    return dist[end];
}

int dijkstraVector(const std::vector<std::vector<int>> &g, int start, int end) {
    int n = g.size();
    std::vector<int> distance(n, std::numeric_limits<int>::max());

    distance[start] = 0;
    std::vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        int minDistance = std::numeric_limits<int>::max();
        int minVertex = -1;
        for (int j = 0; j < n; ++j) {
            if (!visited[j] && distance[j] < minDistance) {
                minDistance = distance[j];
                minVertex = j;
            }
        }

        if (minVertex == -1) {
            return -1;
        }
        visited[minVertex] = true;

        for (int j = 0; j < n; ++j) {
            if (g[minVertex][j] != 0 && !visited[j]) {
                int newDistance = distance[minVertex] + g[minVertex][j];
                if (newDistance < distance[j]) {
                    distance[j] = newDistance;
                }
            }
        }
    }

    return distance[end];
}

// Алгоритм Флойда-Уоршелла
int floydWarshall(const std::vector<std::vector<int>> &g, int start, int end) {
    auto n = g.size();
    const int INF = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> dist(n, std::vector<int>(n, INF));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (g[i][j] != 0) {
                dist[i][j] = g[i][j];
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    return dist[start][end];
}

// Алгоритм Форда-Беллмана
int fordBellman(const std::vector<std::vector<int>> &g, int start, int end) {
    auto n = g.size();
    const int INF = std::numeric_limits<int>::max();

    std::vector<int> dist(n, INF);
    dist[start] = 0;

    for (int k = 0; k < n - 1; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (g[i][j] != 0 && dist[i] != INF && dist[i] + g[i][j] < dist[j]) {
                    dist[j] = dist[i] + g[i][j];
                }
            }
        }
    }

    return dist[end];
}
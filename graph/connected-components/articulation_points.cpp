#pragma once

#include "../graph-template.hpp" 

struct ArticulationPoints {
    size_t vertexCount;
    std::vector<std::vector<size_t>> adjacencyList;

    size_t currentTime;
    std::vector<size_t> discoveryTime;
    std::vector<size_t> lowestTime;
    std::vector<bool> visited;
    std::vector<size_t> articulationPoints;

    // Constructor that accepts a Graph object
    template<typename T>
    ArticulationPoints(const Graph<T>& graph) {
        vertexCount = graph.size();
        adjacencyList.resize(vertexCount);
        for (size_t u = 0; u < vertexCount; ++u) {
            for (const auto& edge : graph.g[u]) {
                adjacencyList[u].push_back(edge.to);
            }
        }
        findArticulationPoints();
    }

    void findArticulationPoints() {
        currentTime = 0;
        discoveryTime.assign(vertexCount, 0);
        lowestTime.assign(vertexCount, 0);
        visited.assign(vertexCount, false);
        articulationPoints.clear();

        for (size_t u = 0; u < vertexCount; ++u) {
            if (!visited[u]) {
                dfs(u, u);
            }
        }
    }

    void dfs(size_t u, size_t parent) {
        visited[u] = true;
        discoveryTime[u] = lowestTime[u] = ++currentTime;
        size_t children = 0;

        for (size_t v : adjacencyList[u]) {
            if (!visited[v]) {
                dfs(v, u);
                lowestTime[u] = std::min(lowestTime[u], lowestTime[v]);
                if (discoveryTime[u] <= lowestTime[v] && u != parent) {
                    articulationPoints.push_back(u);
                }
                ++children;
            } else if (v != parent) {
                lowestTime[u] = std::min(lowestTime[u], discoveryTime[v]);
            }
        }

        if (parent == u && children > 1) {
            articulationPoints.push_back(u);
        }
    }

    std::vector<size_t> getArticulationPoints() const {
        return articulationPoints;
    }
};


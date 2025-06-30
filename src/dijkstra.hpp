#pragma once
#include "graph.hpp"
#include <string>
#include <unordered_map>
#include <vector>

class Dijkstra {
public:
    static std::pair<std::unordered_map<std::string, int>, std::unordered_map<std::string, std::string>>
    shortestPath(const Graph& graph, const std::string& start);
};
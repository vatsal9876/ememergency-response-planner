#include "graph.hpp"

void Graph::addEdge(const std::string& from, const std::string& to, int weight, const std::string& roadType) {
    adjList[from].push_back({to, weight, roadType});
    adjList[to].push_back({from, weight, roadType}); // assuming undirected roads
}

const std::unordered_map<std::string, std::vector<Edge>>& Graph::getAdjList() const {
    return adjList;
}
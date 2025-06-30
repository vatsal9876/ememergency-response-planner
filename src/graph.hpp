#pragma once
#include <unordered_map>
#include <vector>
#include <string>

struct Edge {
    std::string to;
    int weight;
    std::string roadType;
};

class Graph {
public:
    void addEdge(const std::string& from, const std::string& to, int weight, const std::string& roadType);
    const std::unordered_map<std::string, std::vector<Edge>>& getAdjList() const;

private:
    std::unordered_map<std::string, std::vector<Edge>> adjList;
};
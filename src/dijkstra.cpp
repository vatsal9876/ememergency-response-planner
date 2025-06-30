#include "dijkstra.hpp"
#include <queue>
#include <limits>

std::pair<std::unordered_map<std::string, int>, std::unordered_map<std::string, std::string>>
Dijkstra::shortestPath(const Graph& graph, const std::string& start) {
    auto adj = graph.getAdjList();
    std::unordered_map<std::string, int> dist;
    std::unordered_map<std::string, std::string> prev;

    for (const auto& pair : adj)
        dist[pair.first] = std::numeric_limits<int>::max();
    dist[start] = 0;

    using P = std::pair<int, std::string>;
    std::priority_queue<P, std::vector<P>, std::greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
    auto top = pq.top(); pq.pop();
    int currDist = top.first;
    std::string u = top.second;

    if (currDist > dist[u]) continue;

    for (const auto& edge : adj.at(u)) {
        int alt = dist[u] + edge.weight;
        if (alt < dist[edge.to]) {
            dist[edge.to] = alt;
            prev[edge.to] = u;
            pq.push(std::make_pair(alt, edge.to));
        }
    }
}


    return {dist, prev};
}
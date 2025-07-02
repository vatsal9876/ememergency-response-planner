#include "dijkstra.hpp"
#include <queue>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

pair<unordered_map<string, int>, unordered_map<string, string>>
Dijkstra::shortestPath(const Graph& graph, const string& start) {
    auto adj = graph.getAdjList();
    unordered_map<string, int> dist;
    unordered_map<string, string> prev;

    for (const auto& pair : adj)
        dist[pair.first] = numeric_limits<int>::max();
    dist[start] = 0;

    using P = pair<int, string>;
    priority_queue<P, vector<P>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto top = pq.top(); pq.pop();
        int currDist = top.first;
        string u = top.second;

        if (currDist > dist[u]) continue;

        for (const auto& edge : adj.at(u)) {
            int alt = dist[u] + edge.weight;
            if (alt < dist[edge.to]) {
                dist[edge.to] = alt;
                prev[edge.to] = u;
                pq.push({alt, edge.to});
            }
        }
    }

    return {dist, prev};
}

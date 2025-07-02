#include "graph.hpp"
#include "dijkstra.hpp"
#include "map_loader.hpp"
#include <iostream>
using namespace std;

int main() {
    Graph cityGraph;
    MapLoader::loadMapFromFile("maps/city_map.txt", cityGraph);

    string source, destination;
    cout << "Enter source: ";
    cin >> source;
    cout << "Enter destination: ";
    cin >> destination;

    auto p = Dijkstra::shortestPath(cityGraph, source);
    auto distances=p.first;
    auto prev=p.second;


    if (distances[destination] >= 1e9)
        cout << "no reachable path";
    else {
        cout << "Shortest travel time: " << distances[destination] << "\n";
        cout << "Path: ";
        string curr = destination;
        while (curr != source) {
            cout << curr << " <- ";
            curr = prev[curr];
        }
        cout << source << "\n";
    }

    return 0;
}
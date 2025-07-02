#include "map_loader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

using namespace std;

void MapLoader::loadMapFromFile(const string& filename, Graph& graph) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Cannot open map file.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        stringstream ss(line);
        string from, to, roadType;
        int weight;
        ss >> from >> to >> weight >> roadType;

        // int adjustedWeight = weight * roadTypeToWeight(roadType);

        // cout << "[DEBUG] From: " << from
        //      << " → " << to
        //      << " | Base: " << weight
        //      << " | Terrain: " << roadType
        //      << " | Adjusted: " << adjustedWeight << endl;

        graph.addEdge(from, to, weight, roadType);
    }

    file.close();
}

int MapLoader::roadTypeToWeight(const string& roadType) {
    static unordered_map<string, int> weightMap = {
        {"Highway", 2},
        {"Local", 5},
        {"Congested", 10},
        {"Alley", 8},
        {"Blocked", 1000000000}
    };

    auto it = weightMap.find(roadType);
    if (it != weightMap.end()) {
        return it->second;
    } else {
        cerr << "[WARNING] Unknown road type: " << roadType << " — using default cost 10\n";
        return 10;
    }
}

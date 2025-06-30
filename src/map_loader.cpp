#include "map_loader.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>

void MapLoader::loadMapFromFile(const std::string& filename, Graph& graph) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open map file.\n";
        return;
    }

    std::string line;
    while (getline(file, line)) {
        if (line.empty() || line[0] == '#') continue;

        std::stringstream ss(line);
        std::string from, to, roadType;
        int weight;
        ss >> from >> to >> weight >> roadType;

        int adjustedWeight = weight * roadTypeToWeight(roadType);

        // Debug output to verify weight calculation
        std::cout << "[DEBUG] From: " << from
                  << " → " << to
                  << " | Base: " << weight
                  << " | Terrain: " << roadType
                  << " | Adjusted: " << adjustedWeight << std::endl;

        graph.addEdge(from, to, adjustedWeight, roadType);
    }

    file.close();
}

int MapLoader::roadTypeToWeight(const std::string& roadType) {
    static std::unordered_map<std::string, int> weightMap = {
        {"Highway", 2},
        {"Local", 5},
        {"Congested", 10},
        {"Alley", 8},
        {"Blocked", 1000000000}  // effectively infinite
    };

    auto it = weightMap.find(roadType);
    if (it != weightMap.end()) {
        return it->second;
    } else {
        std::cerr << "[WARNING] Unknown road type: " << roadType << " — using default cost 10\n";
        return 10;
    }
}

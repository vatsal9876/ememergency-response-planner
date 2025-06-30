#ifndef MAP_LOADER_HPP
#define MAP_LOADER_HPP

#include "graph.hpp"
#include <string>

class MapLoader {
public:
    static void loadMapFromFile(const std::string& filename, Graph& graph);
    static int roadTypeToWeight(const std::string& roadType);
};

#endif // MAP_LOADER_HPP

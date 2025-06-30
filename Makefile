all: main

main: src/main.cpp src/graph.cpp src/dijkstra.cpp src/map_loader.cpp
	g++ src/*.cpp -o main -std=c++17

clean:
	rm -f main
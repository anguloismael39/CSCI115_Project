// File: main.cpp
#include "MapLoader.h"
#include "Pathfinding.h"

int main() {
    MapLoader mapLoader("map.txt");
    mapLoader.loadMap();

    Pathfinding pathfinder(&mapLoader);
    int startX = mapLoader.getPlayerX();
    int startY = mapLoader.getPlayerY();
    int endX = mapLoader.getEnemy1X();
    int endY = mapLoader.getEnemy1Y();

    int shortestPath = pathfinder.findShortestPath(startX, startY, endX, endY);
    if (shortestPath != INT_MAX) {
        std::cout << "Shortest path from player to enemy1: " << shortestPath << std::endl;
    } else {
        std::cout << "No path found from player to enemy1." << std::endl;
    }

    return 0;
}

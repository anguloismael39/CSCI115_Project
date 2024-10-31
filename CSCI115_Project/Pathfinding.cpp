// File: Pathfinding.cpp
#include "Pathfinding.h"
#include <climits>

Pathfinding::Pathfinding(MapLoader* loader) : mapLoader(loader) {
    const MyVector<MyVector<TerrainType>>& map = mapLoader->getMap();
    int n = map.size();
    distances = MyVector<MyVector<int>>(n, MyVector<int>(n, INT_MAX)); // Initialize distances with INT_MAX
}

int Pathfinding::findShortestPath(int startX, int startY, int endX, int endY) {
    distances[startX][startY] = 0;

    MaxHeap<PathNode> minHeap;
    minHeap.Insert({startX, startY, 0});

    while (!minHeap.isEmpty()) {
        PathNode current = minHeap.Poll();
        int x = current.x, y = current.y;

        if (x == endX && y == endY) return distances[x][y];

        MyVector<std::pair<int, int>> directions(4);
        directions[0] = {0, 1};
        directions[1] = {1, 0};
        directions[2] = {0, -1};
        directions[3] = {-1, 0};

        for (int i = 0; i < directions.size(); i++) {
            int nx = x + directions[i].first;
            int ny = y + directions[i].second;

            if (nx >= 0 && nx < distances.size() && ny >= 0 && ny < distances[0].size() && mapLoader->getMap()[nx][ny] != WALL) {
                int terrainCost = mapLoader->getMap()[nx][ny];
                int newDist = distances[x][y] + terrainCost;

                if (newDist < distances[nx][ny]) {
                    distances[nx][ny] = newDist;
                    minHeap.Insert({nx, ny, newDist});
                }
            }
        }
    }
    return INT_MAX; // No path found
}

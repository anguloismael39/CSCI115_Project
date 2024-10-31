// File: Pathfinding.h
#pragma once
#include "MapLoader.h"
#include "MaxHeap.h"
#include "MyVector.h"

struct PathNode {
    int x, y, dist;

    // Define a custom `operator>` for comparison based on `dist`
    bool operator>(const PathNode& other) const { 
        return dist > other.dist; 
    }

    // The `<` operator is still used in some parts of the code
    bool operator<(const PathNode& other) const { 
        return dist < other.dist; 
    }
};

class Pathfinding {
private:
    MyVector<MyVector<int>> distances;
    MapLoader* mapLoader;

public:
    Pathfinding(MapLoader* loader); // Constructor declaration
    int findShortestPath(int startX, int startY, int endX, int endY); // Function declaration
};

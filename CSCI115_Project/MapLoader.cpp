// File: MapLoader.cpp
#include "MapLoader.h"
#include <fstream>
#include <iostream>
//Can you see this comment?
MapLoader::MapLoader(const char* filename) {
    std::ifstream file(filename);
    if (!file) return;

    int n;
    file >> n;

    map = MyVector<MyVector<TerrainType>>(n);
    for (int i = 0; i < n; i++) {
        MyVector<TerrainType> row(n);
        for (int j = 0; j < n; j++) {
            char tile;
            file >> tile;
            switch (tile) {
                case 'W': row[j] = WALL; break;
                case 'E': row[j] = EMPTY; break;
                case 'D': row[j] = DIRT; break;
                case 'S': row[j] = SECRET_PASSAGE; break;
            }
        }
        map.push_back(row);
    }
    file >> playerX >> playerY >> enemy1X >> enemy1Y >> enemy2X >> enemy2Y;
    file.close();
}

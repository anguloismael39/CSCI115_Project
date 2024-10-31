// File: MapLoader.h
#pragma once
#include "MyVector.h"

enum TerrainType { WALL = -1, EMPTY = 1, DIRT = 3, SECRET_PASSAGE = 2 };

class MapLoader {
private:
    MyVector<MyVector<TerrainType>> map;
    int playerX, playerY;
    int enemy1X, enemy1Y, enemy2X, enemy2Y;

public:
    MapLoader(const char* filename);
    void loadMap();
    const MyVector<MyVector<TerrainType>>& getMap() const { return map; }
    int getPlayerX() const { return playerX; }
    int getPlayerY() const { return playerY; }
    int getEnemy1X() const { return enemy1X; }
    int getEnemy1Y() const { return enemy1Y; }
    int getEnemy2X() const { return enemy2X; }
    int getEnemy2Y() const { return enemy2Y; }
};

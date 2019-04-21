#ifndef MAP_H
#define MAP_H

#include "room.hpp"
#include <vector>
#include <iostream>

using namespace std;

class Map
{
  protected:
    vector< vector<Room> > rooms;
    int mapSize;
    int playerRow;
    int playerCol;
  public:
    Map(int mapSize);
    Map();
    void chooseRoom(int &row, int &col, vector< vector<Room> > rooms);
    void printMap();
    void printMapDebug();
    int getPlayerRow();
    int getPlayerCol();
    void setPlayerRow(int row);
    void setPlayerCol(int col);
    int getMapSize();
    vector< vector<Room> >& getRooms();
};

#endif

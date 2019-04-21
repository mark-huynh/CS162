#ifndef MAZE_H
#define MAZE_H
#include "mazelevel.hpp"
#include <vector>
class Maze
{
  protected:
    vector<MazeLevel> levels;
    int current;
    bool gameState;
    bool startOver;
    int totalLevels;
  public:
    Maze(vector<MazeLevel> v, int totalLevels);
    ~Maze();
    void playerTurn();
    bool getGameState();
    bool getStartOver();
};

#endif

#ifndef GAME_H
#define GAME_H

#include "map.hpp"


class Game
{
  protected:
    int numArrows;
    int hasGold;
    int wumpusDead;
    Map map;

  public:
    Game(int mapSize);
    void playerTurn();
    void nearby();
    void movePlayer(int direction);
    void shootArrow(int direction);
    void checkRoom();
    void endgame();
    void randomMovePlayer();
    void wumpusMove();
    Map getMap();
    int validInput(int range);

};

#endif

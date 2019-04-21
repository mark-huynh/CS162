#ifndef GAME_H
#define GAME_H

#include "card.hpp"
#include "hand.hpp"
#include "deck.hpp"
#include "player.hpp"

class Game
{
  private:
    Deck cards;
    Player players[2];
  public:
  // must have constructors, destructor, accessor methods, and mutator methods
    Game();
    void printPlayerHands();
    void startGame();
    bool gameOver();
    void playerTurn();
    void computerTurn();
    void winner();
};

#endif

/*********************************************************************
** Program Filename: gofish.cpp
** Author: Mark Huynh
** Date: Febuary 3rd, 2019
** Description: A go fish card game between the user and a computer
** Input: Card Selections
** Output: Winner of the Gofish Game
*********************************************************************/
#include <iostream>
#include "card.hpp"
#include "deck.hpp"
#include "hand.hpp"
#include "player.hpp"
#include "game.hpp"

/*********************************************************************
** Function: main()
** Description: Handles main logic of a "Go Fish" game
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: Winner of the game is outputted to the console
*********************************************************************/
int main()
{
  Game goldFish;

  goldFish.startGame();

  int turnCount = 1;

  while(!goldFish.gameOver())
  {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "_____________________________________________________" << endl;
    cout << "     - - - - - - - - - Turn " << turnCount << "- - - - - - - - -" << endl;
    cout << "_____________________________________________________" << endl;
    goldFish.playerTurn();

    goldFish.computerTurn();

    turnCount++;
    cout << "_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _" << endl;
  }

  goldFish.winner();
}

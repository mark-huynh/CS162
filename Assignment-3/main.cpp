
/*********************************************************************
** Program Filename: zoogame
** Author: Mark Huynh
** Date: February 15, 2019
** Description: A text simulation of the Zoo Tycoon Game
** Input: None
** Output: None
*********************************************************************/

#include <iostream>
#include "animal.hpp"
#include "sloth.hpp"
#include "monkey.hpp"
#include "zoo.hpp"
#include "seaotter.hpp"


using namespace std;


/*********************************************************************
** Function: main()
** Description: Contains the highest level logic for this game
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None
*********************************************************************/
int main()
{
  srand(time(NULL));

  Zoo game;
  game.welcomeScreen();
  int i = 0;
  do
  {
    cout << " - - - - - - - - - - - Day " << i << " - - - - - - - - - - -" << endl;
    game.playerTurn();
    i++;
  } /*while(i != 5)*/ /*Use this to test memory leaks*/ while(game.getBank() > 0 && game.getBank() < 1000000);

  if(game.getBank() <= 0)
  {
  	cout << "Game Over! You have lost all your money! Thanks for playing!" << endl;
  }

  if(game.getBank() >= 1000000)
  {
  	cout << "Game Over! You have sucessfully made your $100,000 into $1,000,000! Thanks for playing!" << endl;
  }

}

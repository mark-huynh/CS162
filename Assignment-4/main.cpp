/*********************************************************************
** Program Filename: huntTheWumpus
** Author: Mark Huynh
** Date: March 3rd, 2019
** Description: A program the emulates the game Hunt the Wumpus
** Input: None
** Output: None
*********************************************************************/

#include "wumpus.hpp"
#include "event.hpp"
#include "spawn.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "bats.hpp"
#include "room.hpp"
#include "map.hpp"
#include "game.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    cout << "Please run this program with the size of the map you would like (>= 4).\n";
    return 1;
  }

  try
  {
    if((atoi(argv[1])) < 4)
    {
      cout << "Please run the program with a size greater than or equal to 4\n";
      return 1;
    }
  }
  catch(exception e)
  {
    cout << "Please run an argument that is an integer\n";
    return 1;
  }

  srand(time(NULL));
  try
  {
    if(argc == 3 && (atoi(argv[2])) == 12345)
    {
      Game admin(atoi(argv[1]));

        while(1)
        {
          admin.getMap().printMapDebug();
          admin.playerTurn();
          admin.checkRoom();
        }

    }

    Game test(atoi(argv[1]));
    while(1)
    {
      test.getMap().printMap();
      test.playerTurn();
      test.checkRoom();
    }
  }
  catch(exception e)
  {
    cout << "Game over! Thanks for playing!\n";
  }

}

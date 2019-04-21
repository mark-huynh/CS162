#include "game.hpp"
#include "map.hpp"
#include <iostream>
#include <exception>
#include <istream>

using namespace std;



/*********************************************************************
** Function: Game(int mapSize)
** Description: Parameterized Constructor
** Parameters: desired size of map
** Pre-Conditions: None
** Post-Conditions: Game Object is instantiated
*********************************************************************/
Game::Game(int mapSize)
{
  numArrows = 3;
  hasGold = 0;
  wumpusDead = 0;
  Map t(mapSize);
  this->map = t;
}


/*********************************************************************
** Function: validInput(int range)
** Description: Ensures that a string within the given range is inputted
** Parameters: Range desired for input
** Pre-Conditions: Game Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Game::validInput(int range)
{
  int temp;
  // try
  // {
    cin >> temp;
  // }
  // catch(exception e)
  // {
  //   cout << "Please input a valid integer between 1 and " << range << endl;
  //   cin.clear();
  //   temp = validInput(range);
  // }


  while(cin.fail() || temp < 1 || temp > range)
  {
    cout << "Please input a valid integer between 1 and " << range << endl;
    cin.clear();
    cin.ignore(256, '\n');
    cin >> temp;
  }
  return temp;
}


/*********************************************************************
** Function: getMap()
** Description: getter method for map
** Parameters: none
** Pre-Conditions: Game Object is instantiated
** Post-Conditions: None
*********************************************************************/
Map Game::getMap()
{
  return this->map;
}


/*********************************************************************
** Function: playerTurn()
** Description: Encapsulates everything that occurs on a player turn
** Parameters: none
** Pre-Conditions: Game Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Game::playerTurn()
{
  nearby();
  int action;
  int direction;
  cout << "Would you like to (1) Move or (2) Shoot an arrow?\n";
  action = validInput(2);
  cout << "Which direction? (1)Left (2)Up (3)Down (4) Right\n";
  direction = validInput(4);
  switch(action)
  {
    case 1:
    movePlayer(direction);
    break;
    case 2:
    shootArrow(direction);
    break;
  }
}


/*********************************************************************
** Function: movePlayer(int direction)
** Description: Moves player in the map in the given direction
** Parameters: integer representing the direction
** Pre-Conditions: Game Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Game::movePlayer(int direction)
{
    try
    {
      switch(direction)
      {
        case 1:
        {
          map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol() - 1).setPlayer(1);
          map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol()).setPlayer(0);
          map.setPlayerCol(map.getPlayerCol() - 1);
          // this->map.printMap();
          break;
        }

        case 2:
        {
          map.getRooms().at(map.getPlayerRow() - 1).at(map.getPlayerCol()).setPlayer(1);
          map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol()).setPlayer(0);
          map.setPlayerRow(map.getPlayerRow() - 1);
          // this->map.printMap();
          break;
        }

        case 3:
        {
          map.getRooms().at(map.getPlayerRow() + 1).at(map.getPlayerCol()).setPlayer(1);
          map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol()).setPlayer(0);
          map.setPlayerRow(map.getPlayerRow() + 1);
          // this->map.printMap();
          break;
        }

        case 4:
        {
          map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol() + 1).setPlayer(1);
          map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol()).setPlayer(0);
          map.setPlayerCol(map.getPlayerCol() + 1);
          // this->map.printMap();
          break;
        }
      }
    }
    catch(exception e)
    {
      cout << "You cannot move that way\n";
      playerTurn();
    }
}


/*********************************************************************
** Function: shootArrow(int direction)
** Description: Shoots an arrow in a given direction for up to 3 blocks
** Parameters: integer representing the direction fired
** Pre-Conditions: Game Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Game::shootArrow(int direction)
{
  int i = 1;
  if(numArrows == 0)
  {
    cout << "You are currently out of arrows\n";
    return;
  }
  this->numArrows--;
  try
  {
    switch(direction)
    {
      case 1:
      {
        while(i < 4)
        {
          int playerCol = map.getPlayerCol();
          int playerRow = map.getPlayerRow();
          if(map.getRooms().at(playerRow).at(playerCol - i).getDesignator() == 'W')
          {
              map.getRooms().at(playerRow).at(playerCol - i).deleteDesignator();
              map.getRooms().at(playerRow).at(playerCol - i).deleteEvent();
              this->wumpusDead = 1;
              cout << "You have killed the Wumpus!\n";
          }
          i++;
        }
      }

      case 2:
      {
        while(i < 4)
        {
          int playerCol = map.getPlayerCol();
          int playerRow = map.getPlayerRow();
          if(map.getRooms().at(playerRow - i).at(playerCol).getDesignator() == 'W')
          {
              map.getRooms().at(playerRow - i).at(playerCol).deleteDesignator();
              map.getRooms().at(playerRow - i).at(playerCol).deleteEvent();
              this->wumpusDead = 1;
              cout << "You have killed the Wumpus!\n";
          }
          i++;
        }
      }
      case 3:
      {
        while(i < 4)
        {
          int playerCol = map.getPlayerCol();
          int playerRow = map.getPlayerRow();
          if(map.getRooms().at(playerRow + i).at(playerCol).getDesignator() == 'W')
          {
              map.getRooms().at(playerRow + i).at(playerCol).deleteDesignator();
              map.getRooms().at(playerRow + i).at(playerCol).deleteEvent();
              this->wumpusDead = 1;
              cout << "You have killed the Wumpus!\n";
          }
          i++;
        }

      }

      case 4:
      {
        while(i < 4)
        {
          int playerCol = map.getPlayerCol();
          int playerRow = map.getPlayerRow();
          if(map.getRooms().at(playerRow).at(playerCol + i).getDesignator() == 'W')
          {
              map.getRooms().at(playerRow).at(playerCol + i).deleteDesignator();
              map.getRooms().at(playerRow).at(playerCol + i).deleteEvent();
              this->wumpusDead = 1;
              cout << "You have killed the Wumpus!\n";

          }
          i++;
        }
    }
  }
  if(numArrows == 0 && wumpusDead == 0)
  {
    cout << "You have ran out of arrows and the Wumpus is not dead!\n";
    endgame();
  }
}
  catch(exception e)
  {
    cout << "Your arrow has hit a wall\n";
  }

  if(wumpusDead == 0)
  {
    wumpusMove();
  }

  cout << "You now have " << this->numArrows << " arrows left.\n";
}


/*********************************************************************
** Function: wumpusMove()
** Description: 75% chance of wumpus moving
** Parameters: None
** Pre-Conditions: Game Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Game::wumpusMove()
{
  int chance = rand() % 100;
  if(chance <= 75)
  {
    cout << "The Wumpus was awoken by your arrow shot and moved to a different room\n";
    for(int i = 0; i < map.getMapSize(); i++)
    {
      for(int j = 0; j < map.getMapSize(); j++)
      {
        if(map.getRooms().at(i).at(j).getDesignator() == 'W')
        {
          map.getRooms().at(i).at(j).deleteEvent();
          map.getRooms().at(i).at(j).deleteDesignator();
        }
      }
    }

    int col = rand() % map.getMapSize();
    int row = rand() % map.getMapSize();

    map.getRooms().at(row).at(col).addWumpus();
  }
  else
  {
    cout << "Your arrow missed but luckily it didn't wake up the Wumpus\n";
  }
}


/*********************************************************************
** Function: checkRoom()
** Description: checks if the room that the player is in has an event and calls respective action
** Parameters: None
** Pre-Conditions: Game Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Game::checkRoom()
{
  int test = map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol()).Rencounter();
  switch(test)
  {
    case 0:
    {
      cout << "You have found the treasure! You put it in your backpack\n";
      map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol()).deleteEvent();
      map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol()).deleteDesignator();

      hasGold = 1;
      break;
    }

    case 1:
    cout << "You have ran into the Wumpus!\n";
    endgame();
    break;

    case 2:
    {
      cout << "You have fallen into a pit!\n";
      endgame();
      break;
    }
    case 3:
    {
      cout << "You ran into a bunch of crazy bats! They have carried you to a random room!\n";
     randomMovePlayer();
      break;
    }

    case 4:
    {
      if(hasGold == 1 && wumpusDead == 1)
      {
        cout << "Congratulations! You have won the game\n";
        endgame();
        break;
      }
    }

  }
}


/*********************************************************************
** Function: randomMovePlayer()
** Description: moves the player into a random room
** Parameters: None
** Pre-Conditions: Game Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Game::randomMovePlayer()
{
  int row = rand() % map.getMapSize();
  int col = rand() % map.getMapSize();
  map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol()).setPlayer(0);
  map.setPlayerRow(row);
  map.setPlayerCol(col);
  map.getRooms().at(row).at(col).setPlayer(1);
  checkRoom();
}

void Game::endgame()
{
  throw exception();
}

void Game::nearby()
{
  if(map.getPlayerCol() != map.getMapSize() - 1)
  {
    map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol() + 1).Rpercept();
  }
  if(map.getPlayerRow() != map.getMapSize() - 1)
  {
    map.getRooms().at(map.getPlayerRow() + 1).at(map.getPlayerCol()).Rpercept();
  }
  if(map.getPlayerCol() != 0)
  {
    map.getRooms().at(map.getPlayerRow()).at(map.getPlayerCol() - 1).Rpercept();
  }
  if(map.getPlayerRow() != 0)
  {
    map.getRooms().at(map.getPlayerRow() - 1).at(map.getPlayerCol()).Rpercept();
  }
}

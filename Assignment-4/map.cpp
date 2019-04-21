#include "map.hpp"
#include "wumpus.hpp"
#include "event.hpp"
#include "spawn.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "bats.hpp"
#include "room.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>



/*********************************************************************
** Function: Map(int mapSize)
** Description: Parameterized constructor
** Parameters: desired size of map
** Pre-Conditions: None
** Post-Conditions: Object is instantiated
*********************************************************************/
Map::Map(int mapSize)
{
  this->mapSize = mapSize;
  vector< vector<Room> > temp;
  for(int i = 0; i < mapSize; i++)
  {
    vector<Room> row;
    for(int j = 0; j < mapSize; j++)
    {
      Room r;
      row.push_back(r);
    }
    temp.push_back(row);
  }

  int col = rand() % mapSize;
  int row = rand() % mapSize;

  temp[row][col].addWumpus();
  chooseRoom(row, col, temp);
  temp[row][col].addSpawn();
  this->playerRow = row;
  this->playerCol = col;
  for(int i = 0; i < 2; i++)
  {
    chooseRoom(row, col, temp);
    temp[row][col].addPit();
    chooseRoom(row, col, temp);
    temp[row][col].addBats();
  }
  chooseRoom(row, col, temp);
  temp[row][col].addGold();


  this->rooms = temp;

}


/*********************************************************************
** Function: chooseRoom(int &row, int& col, vector< vector<Room> > rooms)
** Description: chooses a random room that does not have an event inside
** Parameters: row and column variables to be adjusted and the vector of rooms
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Map::chooseRoom(int &row, int& col, vector< vector<Room> > rooms)
{
  while(rooms[row][col].getDesignator() != '\0')
  {
    col = rand() % this->mapSize;
    row = rand() % this->mapSize;
  }
}

Map::Map()
{

}



/*********************************************************************
** Function: printMap()
** Description: Prints out the map w/o events revealed
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Map::printMap()
{
  for(int i = 0; i < mapSize; i++)
  {
    for(int j = 0; j < mapSize; j++)
    {
      this->rooms[i][j].printRoom();
    }
    std::cout << std::endl;
  }
}


/*********************************************************************
** Function: printMapDebug()
** Description: prints out map with events revealed
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Map::printMapDebug()
{
  for(int i = 0; i < mapSize; i++)
  {
    for(int j = 0; j < mapSize; j++)
    {
      this->rooms[i][j].printRoomDebug();
    }
    std::cout << std::endl;
  }
}


/*********************************************************************
** Function: getMapSize()
** Description: Getter Method
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Map::getMapSize()
{
  return mapSize;
}


/*********************************************************************
** Function: getRooms()
** Description: Getter Method
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
vector< vector<Room> >& Map::getRooms()
{
  return this->rooms;
}


/*********************************************************************
** Function:getPlayerRow()
** Description: Getter Method
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Map::getPlayerRow()
{
  return this->playerRow;
}


/*********************************************************************
** Function: getPlayerCol() Setter method
** Description: Getter Method
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Map::getPlayerCol()
{
  return this->playerCol;
}


/*********************************************************************
** Function: setPlayerRow(int row)
** Description: Setter method
** Parameters: integer to set row to
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Map::setPlayerRow(int row)
{
  this->playerRow = row;
}


/*********************************************************************
** Function: setPlayerCol(int col)
** Description: Setter method
** Parameters: integer to set col to
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Map::setPlayerCol(int col)
{
  this->playerCol = col;
}

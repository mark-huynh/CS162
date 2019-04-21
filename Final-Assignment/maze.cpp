#include "maze.hpp"
#include "mazelevel.hpp"


/*********************************************************************
** Function: Maze(std::vector<MazeLevel> v, int totalLevels)
** Description: Parametarized constructor for Maze
** Parameters: Vector of MazeLevel objects and integer of total levels
** Pre-Conditions: None
** Post-Conditions: Maze object is instantiated
*********************************************************************/
Maze::Maze(std::vector<MazeLevel> v, int totalLevels)
{
  levels = v;
  current = 0;
  gameState = true;
  this->totalLevels = totalLevels;

}


/*********************************************************************
** Function: ~Maze()
** Description: Maze Destructor
** Parameters: None
** Pre-Conditions: Maze Object is instantiated
** Post-Conditions: Memory for each mazelevel is deallocated
*********************************************************************/
Maze::~Maze()
{
  for(int i = 0; i < totalLevels; i ++)
  {
    levels[i].desctructorFunction();
  }
}


/*********************************************************************
** Function: playerTurn()
** Description: Encapsulates everything that happens during a player's turn
** Parameters: None
** Pre-Conditions: Maze Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Maze::playerTurn()
{
  for(int i = 0; i < totalLevels; i++)
  {
    levels[i].setProgrammingSkills(levels[current].getProgrammingSkills());
  }
  levels[current].printMazeLevel();
  levels[current].movePlayer(current);
  system("clear");
  levels[current].moveTas();
  gameState = levels[current].checkInteraction(startOver);
}


/*********************************************************************
** Function: getGameState()
** Description: returns whether the game is still ongoing (true) or not (false)
** Parameters: None
** Pre-Conditions: Maze Object is instantiated
** Post-Conditions: None
*********************************************************************/
bool Maze::getGameState()
{
  return gameState;
}


/*********************************************************************
** Function: getStartOver()
** Description: returns whether or not the player will have to start over from the beginning
** Parameters: None
** Pre-Conditions: Maze Object is instantiated
** Post-Conditions: None
*********************************************************************/
bool Maze::getStartOver()
{
  return this->startOver;
}

/*********************************************************************
** Program Filename: EscapeCS162
** Author: Mark Huynh
** Date: March 12th, 2019
** Description: A text-based maze game where you attempt to escape CS 162 as an Intrepid Student
** Input: Text file containing the maze levels that are appropriately formated
** Output: N/A
*********************************************************************/


#include "intrepidstudent.hpp"
#include "mazeperson.hpp"
#include "wall.hpp"
#include "instructor.hpp"
#include "mazelevel.hpp"
#include "mazelocation.hpp"
#include "ta.hpp"
#include "openspace.hpp"
#include "maze.hpp"

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


/*********************************************************************
** Function: main(int argc, char* argv[])
** Description: Handles main logic of the game
** Parameters: Text file containing the maze levels that are appropriately formated
** Pre-Conditions: N/A
** Post-Conditions: N/A
*********************************************************************/
int main(int argc, char* argv[])
{
  string file;
  if(argc == 1)
  {
    cout << "Please execute program with an appropriate maze text file \n";
    return 1;
  }
  else if(argc == 2)
  {
    file = argv[1];
  }
  system("clear");
  srand(time(NULL));
  bool restart = true;
  cout << "------------------------------------------------------\n";
  cout << "------------------Welcome to CS 162-------------------\n";
  cout << "------------------------------------------------------\n";
  cout << "Reach the instructor (%) with at least 3 programming \n";
  cout << "          skills in order to pass the class.\n";
  do
  {
    ifstream infile;
    infile.open(file);
    if(infile.fail())
    {
      cout << "File has failed to open \n";
      return 1;
    }
    int numLevels;
    int levelHeight;
    int levelWidth;

    infile >> numLevels;
    infile >> levelHeight;
    infile >> levelWidth;

    vector<MazeLevel> v;

    for(int i = 0; i < numLevels; i++)
    {
      v.push_back(MazeLevel(infile, levelHeight, levelWidth));
    }

    Maze test(v, numLevels);
    do
    {
      test.playerTurn();
    }while(test.getGameState());
    restart = test.getStartOver();
    if(restart)
    {
      cout << "Oh no!! You failed CS 162 and had to start all over!\n";
    }
    infile.close();
  }while(restart);

  cout << "Congratulations! You have completed CS 162!\n";

}

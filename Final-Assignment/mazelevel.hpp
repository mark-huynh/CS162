#ifndef MAZELEVEL_H
#define MAZELEVEL_H

#include <iostream>
#include <vector>
#include "mazelocation.hpp"
#include "mazeperson.hpp"
#include "openspace.hpp"
#include "wall.hpp"
#include <fstream>

using namespace std;

class MazeLevel
{
  protected:
    vector< vector<MazeLocation*> > currentLevel;
    vector<MazePerson*> mazePeople;
    int taAppease;
    int startRow;
    int startCol;
    bool hasInstructor;
  public:
    MazeLevel(ifstream &f, int levelHeight, int levelWidth);
    // ~MazeLevel();
    void movePlayer(int &level);
    void printMazeLevel();
    void climb(int &level);
    void demonstrateSkill();
    void transfer(char direction, MazePerson* p, int &level);
    void moveTas();
    bool checkInteraction(bool &startOver);
    bool checkAdjacent(MazePerson* p);
    int getProgrammingSkills();
    void setProgrammingSkills(int num);
    void desctructorFunction();


};

#endif

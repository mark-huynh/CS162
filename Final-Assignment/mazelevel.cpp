#include "mazelevel.hpp"
#include <iostream>
#include <vector>
#include "mazelocation.hpp"
#include "mazeperson.hpp"
#include "openspace.hpp"
#include "intrepidstudent.hpp"
#include "instructor.hpp"
#include "ta.hpp"
#include "wall.hpp"
#include <fstream>


/*********************************************************************
** Function: MazeLevel(ifstream &f, int levelHeight, int levelWidth)
** Description: Parametarized constructor for MazeLevel
** Parameters: inputted text file containing mazelevels, the height of each level, the width of each level
** Pre-Conditions: None
** Post-Conditions: MazeLevel object is instantiated
*********************************************************************/
MazeLevel::MazeLevel(ifstream &f, int levelHeight, int levelWidth)
{
  taAppease = 0;
  startCol = 0;
  startRow = 0;
  hasInstructor = false;

  for(int i = 0; i < levelHeight; i++)
  {
    this->currentLevel.push_back(vector<MazeLocation*>(levelWidth));
    for(int j = 0; j < levelWidth; j++)
    {
      char block;
      f.get(block);
      if(block == ' ')
      {
        this->currentLevel[i][j] = new OpenSpace;
      }
      else if(block == '#')
      {
        this->currentLevel[i][j] = new Wall;
      }
      else if(block == '@')
      {
        //memory leak may be happening here? openspace rather than mazelocation
        OpenSpace* t = new OpenSpace;
        t->setStart(true);
        t->setHasStudent(true);
        this->startRow = i;
        this->startCol = j;
        this->currentLevel[i][j] = t;
        MazePerson* student = new IntrepidStudent;
        student->setLocation(i, j);
        mazePeople.push_back(student);
      }
      else if(block == '^')
      {
        OpenSpace* t = new OpenSpace;
        t->setHasLadder(true);
        this->currentLevel[i][j] = t;
      }
      else if(block == '%')
      {
        OpenSpace* t = new OpenSpace;
        t->setHasInstructor(true);
        hasInstructor = true;
        this->currentLevel[i][j] = t;
        MazePerson* teacher = new Instructor;
        teacher->setLocation(i, j);
        mazePeople.push_back(teacher);
      }
      else if(block == '\n')
      {
        j--;
      }
    }
  }

  //CREATE TAS
  int row;
  int col;
  int row1;
  int col1;
  for(int i = 0; i < 2; i++)
  {
    do
    {
      row = rand() % levelHeight;
      col = rand() % levelWidth;
    } while(!currentLevel[row][col]->is_occupiable() && (((OpenSpace*)currentLevel[row][col])->hasTa() == false));
    ((OpenSpace*)currentLevel[row][col])->setHasTa(true);
    MazePerson* ta = new TA;
    ta->setLocation(row, col);
    mazePeople.push_back(ta);
  }
  for(int i = 0; i < 3; i++)
  {
    do
    {
      row1 = rand() % levelHeight;
      col1 = rand() % levelWidth;
    } while(!currentLevel[row1][col1]->is_occupiable());
    ((OpenSpace*)currentLevel[row1][col1])->setHasSkill(true);
  }
}

// MazeLevel::~MazeLevel()
// {
//   for(int i = 0; i < mazePeople.size(); i++)
//   {
//     delete mazePeople[i];
//   }
// }

/*********************************************************************
** Function: printMazeLevel()
** Description: Prints out a text visual of the current mazelevel
** Parameters: None
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
void MazeLevel::printMazeLevel()
{
  cout << "Current Programming Skills: " << ((IntrepidStudent*)mazePeople[0])->getProgrammingSkills() << endl;
  if(taAppease > 0)
  {
    cout << "IMMUNITY STEPS REMAINING: " << taAppease << endl;
  }
  for(int i = 0; i < (this->currentLevel.size()); i++)
  {
    for(int j = 0; j < this->currentLevel[i].size(); j++)
    {
      cout << currentLevel.at(i).at(j)->get_display_character();
    }
    cout << endl;
  }
}

/*********************************************************************
** Function: movePlayer(int &level)
** Description: Calls the getMove() of the IntrepidStudent and handles the returned value
** Parameters: current level that the player is on (integer)
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
void MazeLevel::movePlayer(int &level)
{
  char c = mazePeople[0]->getMove();
  switch(c)
  {
    case 'U':
      climb(level);
      break;
    case 'P':
      demonstrateSkill();
      break;
    case 'N':
      cout << "You do not currently have any programming skills.\n";
      movePlayer(level);
      break;
    default:
      transfer(c, mazePeople[0], level);
  }
}

/*********************************************************************
** Function: climb(int &level)
** Description: If the IntrepidStudent is on a ladder, the level they are on is incremented
** Parameters: The address of the (integer) level the student is on
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
void MazeLevel::climb(int &level)
{
  if(((OpenSpace*)currentLevel[mazePeople[0]->getRow()][mazePeople[0]->getCol()])->hasLadder())
  {
    level++;
  }
  else
  {
    cout << "You are not currently on a ladder\n";
    movePlayer(level);
  }
}

/*********************************************************************
** Function: demonstrateSkill()
** Description: Sets the taAppease value to 10 and decrements the IntrepidStudent's programmingSkills
** Parameters: None
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
void MazeLevel::demonstrateSkill()
{
  this->taAppease = 10;
  ((IntrepidStudent*)mazePeople[0])->decrementProgramming();
}

/*********************************************************************
** Function: transfer(char direction, MazePerson* p, int &level)
** Description: Tranfers either a IntrepidStudent or a TA object from one OpenSpace to an adjacent one
** Parameters: the character representing the direction, the MazePerson to be moved, and the address of the current level
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
void MazeLevel::transfer(char direction, MazePerson* p, int &level)
{
  switch(direction)
  {
    case 'A':
      if(currentLevel[p->getRow()][p->getCol() - 1]->is_occupiable())
      {
        if(p->getType() == 'S')
        {
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol() - 1])->setHasStudent(true);
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->setHasStudent(false);
          p->setLocation(p->getRow(), p->getCol() - 1);

        }
        else if(p->getType() == 'T')
        {
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol() - 1])->setHasTa(true);
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->setHasTa(false);
          p->setLocation(p->getRow(), p->getCol() - 1);
        }
      }
      else
      {
        if(p->getType() == 'S')
        {
          cout << "You cannot move that way!\n";
          movePlayer(level);
        }
        //if TA, then it shouldnt run into this issue
      }
      break;
    case 'W':
      if(currentLevel[p->getRow() - 1][p->getCol()]->is_occupiable())
      {
        if(p->getType() == 'S')
        {
          ((OpenSpace*)currentLevel[p->getRow() - 1][p->getCol()])->setHasStudent(true);
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->setHasStudent(false);
          p->setLocation(p->getRow() - 1, p->getCol());

        }
        else if(p->getType() == 'T')
        {
          ((OpenSpace*)currentLevel[p->getRow() - 1][p->getCol()])->setHasTa(true);
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->setHasTa(false);
          p->setLocation(p->getRow() - 1, p->getCol());
        }
      }
      else
      {
        if(p->getType() == 'S')
        {
          cout << "You cannot move that way!\n";
          movePlayer(level);
        }
        //if TA, then it shouldnt run into this issue
      }
      break;
    case 'D':
      if(currentLevel[p->getRow()][p->getCol() + 1]->is_occupiable())
      {
        if(p->getType() == 'S')
        {
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol() + 1])->setHasStudent(true);
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->setHasStudent(false);
          p->setLocation(p->getRow(), p->getCol() + 1);

        }
        else if(p->getType() == 'T')
        {
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol() + 1])->setHasTa(true);
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->setHasTa(false);
          p->setLocation(p->getRow(), p->getCol() + 1);
        }
      }
      else
      {
        if(p->getType() == 'S')
        {
          cout << "You cannot move that way!\n";
          movePlayer(level);
        }
        //if TA, then it shouldnt run into this issue
      }
      break;
    case 'S':
      if(currentLevel[p->getRow() + 1][p->getCol()]->is_occupiable())
      {
        if(p->getType() == 'S')
        {
          ((OpenSpace*)currentLevel[p->getRow() + 1][p->getCol()])->setHasStudent(true);
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->setHasStudent(false);
          p->setLocation(p->getRow() + 1, p->getCol());

        }
        else if(p->getType() == 'T')
        {
          ((OpenSpace*)currentLevel[p->getRow() + 1][p->getCol()])->setHasTa(true);
          ((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->setHasTa(false);
          p->setLocation(p->getRow() + 1, p->getCol());
        }
      }
      else
      {
        if(p->getType() == 'S')
        {
          cout << "You cannot move that way!\n";
          movePlayer(level);
        }
        //if TA, then it shouldnt run into this issue
      }
      break;
  }
}

/*********************************************************************
** Function: moveTas()
** Description: calls the getMove() function for each TA on the MazeLevel and moves them appropriately
** Parameters: None
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
void MazeLevel::moveTas()
{
  int dummy;
  char c;
  int startValue;
  if(hasInstructor == false)
  {
    startValue = 1;
  }
  else
  {
    startValue = 2;
  }
  for(int i = startValue; i < mazePeople.size(); i++)
  {
      MazePerson* p = mazePeople[i];
      c = p->getMove();
      switch (c)
      {
        case 'A':
          if(currentLevel[p->getRow()][p->getCol() - 1]->is_occupiable() && ((OpenSpace*)currentLevel[p->getRow()][p->getCol() - 1])->hasTa() == false)
          {
            transfer(c, p, dummy);
          }
          else
          {
              i--;
          }
          break;
        case 'S':
          if(currentLevel[p->getRow() + 1][p->getCol()]->is_occupiable() && ((OpenSpace*)currentLevel[p->getRow() + 1][p->getCol()])->hasTa() == false)
          {
            transfer(c, p, dummy);
          }
          else
          {
              i--;
          }
          break;
        case 'D':
          if(currentLevel[p->getRow()][p->getCol() + 1]->is_occupiable() && ((OpenSpace*)currentLevel[p->getRow()][p->getCol() + 1])->hasTa() == false)
          {
            transfer(c, p, dummy);
          }
          else
          {
              i--;
          }
          break;
        case 'W':
          if(currentLevel[p->getRow() - 1][p->getCol()]->is_occupiable() && ((OpenSpace*)currentLevel[p->getRow() - 1][p->getCol()])->hasTa() == false)
          {
            transfer(c, p, dummy);
          }
          else
          {
              i--;
          }
          break;
      }
  }
}

/*********************************************************************
** Function: checkInteraction(bool &startOver)
** Description: Checks if IntrepidStudent is adjacent or on any other MazePerson or is on a Skill and logic is handled appropriately
** Parameters: address of boolean representing if player will need to start over or not
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: startOver is set to true if student have less than 3 programming skills when instructor is reached
*********************************************************************/
bool MazeLevel::checkInteraction(bool &startOver)
{
  int playerRow = mazePeople[0]->getRow();
  int playerCol = mazePeople[0]->getCol();

  if(((OpenSpace*)currentLevel[playerRow][playerCol])->hasSkill())
  {
    ((IntrepidStudent*)mazePeople[0])->setProgrammingSkills(((IntrepidStudent*)mazePeople[0])->getProgrammingSkills() + 1);
    ((OpenSpace*)currentLevel[playerRow][playerCol])->setHasSkill(false);
  }

  int startValue;
  if(hasInstructor == false)
  {
    startValue = 1;
  }
  else
  {
    startValue = 2;
  }
  if(taAppease != 0)
  {
    taAppease--;
  }
  else
  {
    for(int i = startValue; i < mazePeople.size(); i++)
    {
      MazePerson* p = mazePeople[i];
      if(checkAdjacent(p))
      {
        cout << "Oh no you have been caught by a TA! You lost all of your programming skills and started back at the beginning of this floor\n";
        ((IntrepidStudent*)mazePeople[0])->setProgrammingSkills(0);
        ((OpenSpace*)currentLevel[playerRow][playerCol])->setHasStudent(false);
        ((OpenSpace*)currentLevel[startRow][startCol])->setHasStudent(true);
        mazePeople[0]->setLocation(startRow, startCol);
      }
    }
  }

  if(hasInstructor && (mazePeople[0]->getRow() == mazePeople[1]->getRow()) && (mazePeople[0]->getCol() == mazePeople[1]->getCol()))
  {
    if(((IntrepidStudent*)mazePeople[0])->getProgrammingSkills() >= 3)
    {
      startOver = false;
      return false;
    }
    else
    {
      startOver = true;
      return false;
    }
  }
  return true;


}

/*********************************************************************
** Function: checkAdjacent(MazePerson* p)
** Description: checks if an IntrepidStudent is adjacent or on the passed in MazePerson
** Parameters: MazePerson to be checked
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
bool MazeLevel::checkAdjacent(MazePerson* p)
{
  if(currentLevel[p->getRow()][p->getCol() - 1]->is_occupiable() && ((OpenSpace*)currentLevel[p->getRow()][p->getCol() - 1])->hasStudent() == true)
  {
    return true;
  }
  if(currentLevel[p->getRow()][p->getCol() + 1]->is_occupiable() && ((OpenSpace*)currentLevel[p->getRow()][p->getCol() + 1])->hasStudent() == true)
  {
    return true;
  }
  if(currentLevel[p->getRow() - 1][p->getCol()]->is_occupiable() && ((OpenSpace*)currentLevel[p->getRow() - 1][p->getCol()])->hasStudent() == true)
  {
    return true;
  }
  if(currentLevel[p->getRow() + 1][p->getCol()]->is_occupiable() && ((OpenSpace*)currentLevel[p->getRow() + 1][p->getCol()])->hasStudent() == true)
  {
    return true;
  }
  if(((OpenSpace*)currentLevel[p->getRow()][p->getCol()])->hasStudent() == true)
  {
    return true;
  }
  return false;
}

/*********************************************************************
** Function: getProgrammingSkills()
** Description: returns the amount of programming skills the IntrepidStudent has on this level
** Parameters: None
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
int MazeLevel::getProgrammingSkills()
{
  int num = ((IntrepidStudent*)mazePeople[0])->getProgrammingSkills();
  return num;
}


/*********************************************************************
** Function: setProgrammingSkills(int num)
** Description: sets the amount of programming skills the IntrepidStudent has on this level
** Parameters: number to set the programming skills to (integer)
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: None
*********************************************************************/
void MazeLevel::setProgrammingSkills(int num)
{
  ((IntrepidStudent*)mazePeople[0])->setProgrammingSkills(num);
}

/*********************************************************************
** Function: desctructorFunction()
** Description: function that will be called in the Maze destructor to deallocate all mazeLevels
** Parameters: None
** Pre-Conditions: MazeLevel object is instantiated
** Post-Conditions: MazeLevel is destructed and memory is deallocated
*********************************************************************/
void MazeLevel::desctructorFunction()
{
  for(int i = 0; i < mazePeople.size(); i++)
  {
    delete mazePeople[i];
  }
  for(int i = 0; i < currentLevel.size(); i++)
  {
    for(int j = 0; j < currentLevel[i].size(); j++)
    {
      delete currentLevel[i][j];
    }
  }
}

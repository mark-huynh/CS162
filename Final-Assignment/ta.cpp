#include "ta.hpp"
#include <ctime>
#include <cstdlib>

/*********************************************************************
** Function: TA()
** Description: Default constructor for TA
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: TA object is instantiated
*********************************************************************/
TA::TA()
{
  this->type = 'T';
}


/*********************************************************************
** Function: getMove()
** Description: returns a random character representing the move of a TA object
** Parameters: none
** Pre-Conditions: TA object is instantiated
** Post-Conditions: None
*********************************************************************/
char TA::getMove()
{
  int move = rand() % 4;
  switch(move)
  {
    case 0:
      return 'A';
    case 1:
      return 'S';
    case 2:
      return 'D';
    case 3:
      return 'W';
  }
}

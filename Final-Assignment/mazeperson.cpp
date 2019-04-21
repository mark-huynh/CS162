#include "mazeperson.hpp"


/*********************************************************************
** Function: getRow()
** Description: returns the current row that the MazePerson is on
** Parameters: None
** Pre-Conditions: MazePerson child is instantiated
** Post-Conditions: None
*********************************************************************/
int MazePerson::getRow()
{
  return row;
}


/*********************************************************************
** Function: getCol()
** Description: returns the current column that the MazePerson is on
** Parameters: None
** Pre-Conditions: MazePerson child is instantiated
** Post-Conditions: None
*********************************************************************/
int MazePerson::getCol()
{
  return col;
}


/*********************************************************************
** Function: getType()
** Description: returns the character representing what kind of MazePerson the child is
** Parameters: None
** Pre-Conditions: MazePerson child is instantiated
** Post-Conditions: None
*********************************************************************/
char MazePerson::getType()
{
  return type;
}


/*********************************************************************
** Function: setLocation(int row, int col)
** Description: sets the location of the MazePerson
** Parameters: the row and column to set the MazePerson to (both ints)
** Pre-Conditions: MazePerson child is instantiated
** Post-Conditions: None
*********************************************************************/
void MazePerson::setLocation(int row, int col)
{
  this->row = row;
  this->col = col;
}

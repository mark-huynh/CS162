#include "wall.hpp"
/*********************************************************************
** Function: is_occupiable()
** Description: Always returns false since a wall is not occupiable
** Parameters: None
** Pre-Conditions: Wall object is instantiated
** Post-Conditions: None
*********************************************************************/
bool Wall::is_occupiable()
{
  return false;
}


/*********************************************************************
** Function: get_display_character()
** Description: returns # character to represent wall
** Parameters: None
** Pre-Conditions: Wall object is instantiated
** Post-Conditions: None
*********************************************************************/
char Wall::get_display_character()
{
  return '#';
}

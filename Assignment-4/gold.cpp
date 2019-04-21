#include "gold.hpp"
#include <iostream>

/*********************************************************************
** Function: encounter()
** Description: Overidden function for encounter in event
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Gold::encounter()
{
  return 0;
}
/*********************************************************************
** Function: percept()
** Description: Overidden function for percept in event
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Gold::percept()
{
  std::cout << "You see a glimmer nearby.\n";
}

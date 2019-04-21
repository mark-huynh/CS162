#include <iostream>
#include "wumpus.hpp"


/*********************************************************************
** Function: encounter()
** Description: Overidden function for encounter in event
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Wumpus::encounter()
{
  return 1;
}

/*********************************************************************
** Function: percept()
** Description: Overidden function for percept in event
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Wumpus::percept()
{
  std::cout << "You smell a terrible stench.\n";
}

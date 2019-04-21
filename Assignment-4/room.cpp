#include "room.hpp"
#include "wumpus.hpp"
#include "event.hpp"
#include "spawn.hpp"
#include "gold.hpp"
#include "pit.hpp"
#include "bats.hpp"
#include <iostream>


/*********************************************************************
** Function: Room()
** Description: constructor
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Object is instantiated
*********************************************************************/
Room::Room()
{
  this->event = NULL;
  this->designator = '\0';
  player = 0;
}


/*********************************************************************
** Function: Rpercept()
** Description: calls percept of event
** Parameters: none
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::Rpercept()
{
  if(this->event != NULL)
  {
    event->percept();
  }
}


/*********************************************************************
** Function: Rencounter()
** Description: calls encounter of event
** Parameters: none
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
int Room::Rencounter()
{
  if(this->event != NULL)
  {
      return event->encounter();
  }
  return 6;
}


/*********************************************************************
** Function: deleteDesignator()
** Description: removes designator in room
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::deleteDesignator()
{
  this->designator = '\0';
}


/*********************************************************************
** Function: deleteEvent()
** Description: removes event in room
** Parameters: none
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::deleteEvent()
{
  this->event = NULL;
}


/*********************************************************************
** Function: setPlayer(int playerVal)
** Description: Setter method
** Parameters: value to set player to
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::setPlayer(int playerVal)
{
  this->player = playerVal;
}
// Room::~Room()
// {
//   if(this->event != NULL)
//   {
//     delete this->event;
//   }
// }


/*********************************************************************
** Function: getEvent()
** Description: Getter method
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
Event* Room::getEvent()
{
  return this->event;
}


/*********************************************************************
** Function: getDesignator()
** Description: Getter method
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
char Room::getDesignator()
{
  return this->designator;
}


/*********************************************************************
** Function: addBats()
** Description: Adds specific event into room
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::addBats()
{
  if(this->event != NULL)
  {
    delete this->event;
  }
  this->event = new Bats;
  this->designator = 'B';
}



/*********************************************************************
** Function: addGold()
** Description: Adds specific event into room
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::addGold()
{
  if(this->event != NULL)
  {
    delete this->event;
  }
  this->event = new Gold;
  this->designator = 'G';

}


/*********************************************************************
** Function: addWumpus()
** Description: Adds specific event into room
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::addWumpus()
{
  if(this->event != NULL)
  {
    delete this->event;
  }
  this->event = new Wumpus;
  this->designator = 'W';

}


/*********************************************************************
** Function: addSpawn()
** Description: Adds specific event into room
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::addSpawn()
{
  this->player = 1;
  if(this->event != NULL)
  {
    delete this->event;
  }
  this->event = new Spawn;
  this->designator = 'S';
}


/*********************************************************************
** Function: addPit()
** Description: Adds specific event into room
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::addPit()
{
  if(this->event != NULL)
  {
    delete this->event;
  }
  this->event = new Pit;
  this->designator = 'P';
}


/*********************************************************************
** Function: printRoom()
** Description: print out room w/o event revealed
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::printRoom()
{
  if(this->player != 0)
  {
      std::cout << "  O  ";
  }
  else
  {
    std::cout << "  *  ";
  }
}


/*********************************************************************
** Function: printRoomDebug()
** Description: print out room with event revealed
** Parameters: None
** Pre-Conditions: Object is instantiated
** Post-Conditions: None
*********************************************************************/
void Room::printRoomDebug()
{
  if(this->player != 0)
  {
      std::cout << "  O" << this->designator << "  ";
  }
  else if(this->designator == '\0')
  {
    std::cout << "  *  ";
  }
  else
  {
    std::cout << "  " << this->designator << "  ";
  }
}

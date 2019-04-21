#ifndef ROOM_H
#define ROOM_H

#include "event.hpp"

class Room
{
  protected:
    Event *event;
    char designator;
    int player;
  public:
    Room();
    // ~Room();
    Event* getEvent();
    // template <class T>
    // void addEvent()
    // {
    //   this->event  = new T;
    // }
    char getDesignator();
    void deleteDesignator();
    void deleteEvent();
    void addBats();
    void setPlayer(int playerVal);
    void addGold();
    void addWumpus();
    void addSpawn();
    void addPit();
    void printRoomDebug();
    void printRoom();
    void Rpercept();
    int Rencounter();


};


#endif

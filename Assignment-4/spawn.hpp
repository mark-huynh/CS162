#ifndef SPAWN_H
#define SPAWN_H

#include "event.hpp"

class Spawn: public Event
{
public:
  int encounter();
  void percept();
};

#endif

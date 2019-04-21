#ifndef PIT_H
#define PIT_H

#include "event.hpp"

class Pit: public Event
{
public:
  int encounter();
  void percept();
};

#endif

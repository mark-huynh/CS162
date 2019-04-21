#ifndef GOLD_H
#define GOLD_H

#include "event.hpp"

class Gold: public Event
{
public:
  int encounter();
  void percept();
};

#endif

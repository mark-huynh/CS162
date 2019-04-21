#ifndef BATS_H
#define BATS_H

#include "event.hpp"

class Bats: public Event
{
public:
  int encounter();
  void percept();
};

#endif

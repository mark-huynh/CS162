#include "event.hpp"

class Wumpus: public Event
{
  public:
    int encounter();
    void percept();
};

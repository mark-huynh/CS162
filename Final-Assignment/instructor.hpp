#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include "mazeperson.hpp"

class Instructor : public MazePerson
{
  public:
      Instructor();
      char getMove();
};

#endif

#ifndef INTREPIDS_H
#define INTREPIDS_H

#include "mazeperson.hpp"

class IntrepidStudent : public MazePerson
{
  protected:
    int programmingSkills;
  public:
    IntrepidStudent();
    char getMove();
    int getProgrammingSkills();
    void setProgrammingSkills(int num);
    void decrementProgramming();
};

#endif

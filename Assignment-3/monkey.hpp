#ifndef MONKEY_H
#define MONKEY_H

#include "animal.hpp"

class Monkey: public Animal
{
  protected:
    int bonusRev;
  public:
    Monkey();
    Monkey(int age);
    // Monkey(const Monkey& m);
    void setbonusRev();
    int getbonusRev();
};

#endif

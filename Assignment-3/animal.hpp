#ifndef ANIMAL_H
#define ANIMAL_H

class Animal
{
  protected:
    int foodCost;
    int age;
    int cost;
    int birthNum;
    int revenue;

  public:
    Animal();
    void changeFoodCost(float percent);
    int getfoodCost();
    int getAge();
    int getCost();
    int getbirthNum();
    int getRevenue();
    void setfoodCost(int n);
    void setAge(int n);
    void setCost(int n);
    void setbirthNum(int n);
    void setRevenue(int n);
};

#endif

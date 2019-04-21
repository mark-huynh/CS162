#ifndef OPENSPACE_H
#define OPENSPACE_H

#include "mazelocation.hpp"

class OpenSpace : public MazeLocation
{
  protected:
    bool start;
    bool student;
    bool ta;
    bool instructor;
    bool ladder;
    bool skill;


  public:
    OpenSpace();
    bool is_occupiable();
    char get_display_character();
    bool hasStudent();
    bool hasTa();
    bool hasInstructor();
    bool hasLadder();
    bool hasSkill();
    void setHasStudent(bool status);
    void setHasTa(bool status);
    void setHasInstructor(bool status);
    void setHasLadder(bool status);
    void setHasSkill(bool status);
    void setStart(bool status);
    bool isStart();
};

#endif

#ifndef WALL_H
#define WALL_H

#include "mazelocation.hpp"

class Wall : public MazeLocation
{
  protected:

  public:
    bool is_occupiable();
    char get_display_character();
};

#endif

#ifndef MAZE_LOCATION
#define MAZE_LOCATION

class MazeLocation
{
  protected:

  public:
    virtual bool is_occupiable() = 0;
    virtual char get_display_character() = 0;
};


#endif

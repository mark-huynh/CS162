#ifndef MAZEPERSON_H
#define MAZEPERSON_H

class MazePerson
{
  protected:
    char type;
    int row;
    int col;
  public:
    int getRow();
    int getCol();
    char getType();
    void setLocation(int row, int col);
    virtual char getMove() = 0;
};

#endif

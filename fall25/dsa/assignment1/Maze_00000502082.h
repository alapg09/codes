#ifndef MAZE_00000502082_H
#define MAZE_00000502082_H

#include <string>
using namespace std;

struct Coordinate
{
    int row;
    int column;
    Coordinate(int r = -1, int c = -1)
    {
        row = r;
        column = c;
    }
    bool operator==(const Coordinate &other) const // overloading for easier comparison
    {
        return row == other.row && column == other.column;
    }
};

class Maze
{
private:
    char **grid; // dynamically alloted 2D grid
    Coordinate start, goal;
    int rows, columns;

public:
    Maze();
    bool loadMaze(string filepath);
    int getRows();
    int getColumns();
    char getCell(Coordinate c);
    void setCell(Coordinate c, char new_val);
    Coordinate getStart();
    void setStart(Coordinate c);
    Coordinate getGoal();
    void setGoal(Coordinate c);
    void printGrid();
};

#endif
#ifndef MAZE_00000502082_H
#define MAZE_00000502082_H

#include <string>
using namespace std;

struct Coordinate
{
    int row;
    int column;
    Coordinate(int r = -1, int c = -1) : row(r), column(c) {} // constructor
    bool operator==(const Coordinate &other) const            // overloading for easeir comparison
    {
        return row == other.row && column == other.column;
    }
    bool operator!=(const Coordinate &other) const
    {
        return !(*this == other);
    }
};

class Maze
{
private:
    char **grid;
    int rows;
    int cols;
    Coordinate start, goal;

public:
    Maze();
    ~Maze(); // Destructor to free memory

    bool loadMaze(const string &filepath);
    int getWidth() const;
    int getHeight() const;
    char getCell(const Coordinate &c) const;
    void setCell(const Coordinate &c, char new_val);
    Coordinate getStart() const;
    Coordinate getGoal() const; // const to prevent modifying
    void setStart(Coordinate c);
    void setGoal(Coordinate c);
    void printGrid() const;
};

#endif
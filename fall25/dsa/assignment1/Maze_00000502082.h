#ifndef MAZE_00000502082_H
#define MAZE_00000502082_H

#include <string>
using namespace std;

class Maze
{
private:
    char **grid; // dynamically alloted 2D grid

public:
    bool loadMaze(string filepath);
};

#endif
#ifndef SOLVER_00000502082_H
#define SOLVER_00000502082_H

#include "Maze_00000502082.h"
#include <string>

using namespace std;

class Solver
{
private:
    Coordinate **parent; // parent array
    bool **visited;      // explored set (true/false)
    int rows, cols;

    void allocateStructures(int r, int c);
    void freeStructures();

public:
    Solver(); // constructor and destructor
    ~Solver();

    // this will solve DFS using a stack and fills parent array.
    // Returns true if a path is found, false otherwise.
    bool solve(Maze &maze);

    // parent array to CSV filename (parent_array_output.csv by default)
    bool writeParentArray(const string &filename) const;
};

#endif
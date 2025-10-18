#include <iostream>
#include <fstream>
#include "Maze_00000502082.h"
#include "Solver_00000502082.h"

using namespace std;

int main(int argc, char *argv[]) // taking file name as input from command
{
    string inputFile = "input.csv"; // default
    if (argc >= 2)                  // custom
        inputFile = argv[1];

    Maze maze;                     // new maze
    if (!maze.loadMaze(inputFile)) // loading maze
    {
        cerr << "Failed to load maze from file: " << inputFile << endl;
        return 1;
    }

    cout << "Loaded maze (" << maze.getHeight() << "x" << maze.getWidth() << "):\n"; // acknowlegdment
    maze.printGrid();

    Solver solver; // solver obk

    bool ok = solver.solve(maze);
    if (ok) // sol found
    {
        cout << "Path found. Grid with path (*):\n";
        maze.printGrid();
    }
    else
    {
        cout << "No path found from S to E.\n";
    }

    // write parent array to required file
    if (!solver.writeParentArray("parent_array_output.csv"))
    {
        cerr << "Failed to write parent array output." << endl;
    }
    else
    {
        cout << "Parent array written to parent_array_output.csv\n";
    }

    // writing solved maze to a file named solved_output.csv
    ofstream fout("solved_output.csv");
    if (fout.is_open())
    {
        for (int r = 0; r < maze.getHeight(); r++)
        {
            for (int c = 0; c < maze.getWidth(); c++)
            {
                fout << maze.getCell(Coordinate(r, c));
                if (c < maze.getWidth() - 1)
                    fout << ",";
            }
            fout << "\n";
        }
        fout.close();
    }

    return 0;
}

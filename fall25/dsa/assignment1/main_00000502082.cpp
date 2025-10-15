#include <iostream>
#include "Maze_00000502082.h"

int main()
{

    cout << "=== Maze Loader ===" << endl;

    string filepath;
    cout << "Enter CSV file path: ";
    getline(cin, filepath);

    Maze maze;

    if (!maze.loadMaze(filepath))
    {
        cout << "\nFailed to load maze file.\n";
        return 1;
    }

    cout << "\n\nbaze loaded successfully!" << endl;
    cout << "Rows: " << maze.getRows() << endl;
    cout << "Columns: " << maze.getColumns() << endl;

    cout << "\n--- Maze Grid ---\n";
    maze.printGrid();

    return 0;
}
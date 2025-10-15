#include "Maze_00000502082.h"
#include <iostream>
#include <fstream> // file handling
#include <sstream> // helps in reading from csv

using namespace std;

// constructor
Maze::Maze()
{
    start = Coordinate(-1, -1);
    goal = Coordinate(-1, -1);

    columns = 0;
    rows = 0;
    grid = nullptr;
}

bool Maze::loadMaze(string filepath)
{
    ifstream fin(filepath);

    if (!fin.is_open())
    {
        cout << "Error Opening File!" << endl;
        return false;
    }

    string line;

    while (getline(fin, line))
    {
        rows++; // rows

        if (rows == 1) // to count the columns once
        {
            stringstream ss(line);
            string cell;

            while (getline(ss, cell, ','))
                columns++; // count columns from the first row only
        }
    }
    fin.clear();  // clear EOF flag
    fin.seekg(0); // go back to file start

    // creating the grid
    grid = new char *[rows];
    for (int i = 0; i < rows; i++)
        grid[i] = new char[columns];

    // pupulating
    int r = 0;
    while (getline(fin, line) && r < rows)
    {
        stringstream ss(line);
        string cell;
        int c = 0;

        while (getline(ss, cell, ',') && c < columns)
        {

            if (cell == " ")
                grid[r][c] = ' '; // " " as empty cell
            else
                grid[r][c] = cell[0]; // take first character
            c++;
        }
        r++;
    }
    fin.close();

    cout << "Grid Loaded Successfully";
    printGrid();
    return true;
}

int Maze::getRows()
{
    return rows;
}
int Maze::getColumns()
{
    return columns;
}

char Maze::getCell(Coordinate c)
{
    return grid[c.row][c.column];
}

void Maze::setCell(Coordinate c, char new_val)
{
    grid[c.row][c.column] = new_val;
}

Coordinate Maze::getStart()
{
    return start;
}
void Maze::setStart(Coordinate c)
{
    start = c;
}
Coordinate Maze::getGoal()
{
    return goal;
}
void Maze::setGoal(Coordinate c)
{
    goal = c;
}

void Maze::printGrid()
{
    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < columns; ++c)
        {
            cout << grid[r][c];
        }
        cout << '\n';
    }
}

#include "Maze_00000502082.h"
#include <iostream>
#include <vector>
#include <fstream> // file handling
#include <sstream> // helps in reading from csv

using namespace std;

// constructor
Maze::Maze() : grid(nullptr), rows(0), cols(0), start(-1, -1), goal(-1, -1) {}

// destructor
Maze::~Maze()
{
    if (grid != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] grid[i];
        }
        delete[] grid;
        grid = nullptr;
    }
}

bool Maze::loadMaze(const string &filepath)
{
    ifstream fin(filepath);

    if (!fin.is_open())
    {
        cout << "Error Opening File!" << filepath << endl;
        return false;
    }

    // readning all lines first to determine rows and cols
    vector<vector<char>> temp;
    string line;
    int maxCols = 0; // to keep track of max cols (safe check )
    while (getline(fin, line))
    {
        vector<char> rowVals;
        stringstream ss(line);
        string token;
        while (getline(ss, token, ','))
        {
            // token may be empty -- empty cell
            if (token.size() == 0)
            {
                rowVals.push_back(' ');
            }
            else
            {
                // take first character of token as cell content
                rowVals.push_back(token[0]);
            }
        }
        if (!rowVals.empty())
        {
            if ((int)rowVals.size() > maxCols) // making sure that max cols are used
                maxCols = (int)rowVals.size();
            temp.push_back(move(rowVals)); // move ftn transfers ownership instead of copying
        }
    }
    fin.close();

    if (temp.empty()) // validation
    {
        cerr << "Input file is empty or malformed." << endl;
        return false;
    }

    rows = (int)temp.size();
    cols = maxCols;

    // allocate dynamic grid
    grid = new char *[rows];
    for (int r = 0; r < rows; r++)
    {
        grid[r] = new char[cols]; // array of vectors
        for (int c = 0; c < cols; c++)
        {
            if (c < (int)temp[r].size()) // making sure to stay in bounds
                grid[r][c] = temp[r][c];
            else
                grid[r][c] = ' ';

            // detect start and goal
            if (grid[r][c] == 'S')
            {
                start = Coordinate(r, c);
            }
            else if (grid[r][c] == 'E')
            {
                goal = Coordinate(r, c);
            }
        }
    }

    return true;
}

int Maze::getWidth() const { return cols; }
int Maze::getHeight() const { return rows; }

char Maze::getCell(const Coordinate &c) const
{
    if (c.row < 0 || c.row >= rows || c.column < 0 || c.column >= cols) // safe check
        return '#';
    return grid[c.row][c.column];
}

void Maze::setCell(const Coordinate &c, char new_val)
{
    if (c.row < 0 || c.row >= rows || c.column < 0 || c.column >= cols)
        return;
    grid[c.row][c.column] = new_val;
}

Coordinate Maze::getStart() const { return start; }
Coordinate Maze::getGoal() const { return goal; }
void Maze::setStart(Coordinate c) { start = c; }
void Maze::setGoal(Coordinate c) { goal = c; }

void Maze::printGrid() const
{
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            cout << grid[r][c];
            if (c < cols - 1)
                cout << ',';
        }
        cout << '\n';
    }
}
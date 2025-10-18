#include "Solver_00000502082.h"
#include <stack>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//  stack class for DFS like we did in class
template <typename T>
class Stack
{
private:
    T *arr; // dynamic array
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack() { delete[] arr; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }

    void push(const T &item)
    {
        if (isFull())
        {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = item;
    }

    T pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!\n";
            // Return a default-constructed value for type T
            return T();
        }
        return arr[top--];
    }

    T peek()
    {
        if (isEmpty())
            return T();
        return arr[top];
    }

    void clear() { top = -1; }
};

Solver::Solver() : parent(nullptr), visited(nullptr), rows(0), cols(0) {}

Solver::~Solver()
{
    freeStructures(); // function for destruction
}

void Solver::allocateStructures(int r, int c)
{
    freeStructures(); // making sure to free them first

    // initializing everything
    rows = r;
    cols = c;
    parent = new Coordinate *[rows];
    visited = new bool *[rows];

    for (int i = 0; i < rows; i++)
    {
        parent[i] = new Coordinate[cols];
        visited[i] = new bool[cols];

        for (int j = 0; j < cols; j++)
        {
            parent[i][j] = Coordinate(-2, -2); // -2,-2 means unvisited -- as -1 is parent of 0
            visited[i][j] = false;
        }
    }
}

void Solver::freeStructures()
{
    // freeing the memory
    if (parent != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] parent[i];
        }
        delete[] parent;
        parent = nullptr;
    }
    if (visited != nullptr)
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] visited[i];
        }
        delete[] visited;
        visited = nullptr;
    }
    rows = cols = 0;
}

bool Solver::solve(Maze &maze)
{
    Coordinate start = maze.getStart();
    Coordinate goal = maze.getGoal();
    if (start.row == -1 || goal.row == -1)
    { // validation
        cerr << "Start or Goal not found in maze." << endl;
        return false;
    }

    int R = maze.getHeight();
    int C = maze.getWidth();
    allocateStructures(R, C);

    // mark walls in parent as (-9,-9) to indicate invalid cell
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            Coordinate cur(i, j);
            char ch = maze.getCell(cur);
            if (ch == '#')
                parent[i][j] = Coordinate(-9, -9);
        }
    }

    Stack<Coordinate> st(R * C);
    ; // creating a stack of coordinates - estimamte max size = r*c
    st.push(start);
    visited[start.row][start.column] = true;
    parent[start.row][start.column] = Coordinate(-1, -1); // start parent sentinel

    const int dr[4] = {-1, 1, 0, 0}; // direction arrays
    const int dc[4] = {0, 0, -1, 1};

    bool found = false;
    while (!st.isEmpty())
    {
        Coordinate cur = st.pop();

        if (cur == goal)
        {
            found = true;
            break;
        }

        for (int k = 0; k < 4; k++) // exploring all 4 direction
        {
            int nr = cur.row + dr[k];
            int nc = cur.column + dc[k];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) // out of bonds
                continue;
            Coordinate nb(nr, nc);
            char cell = maze.getCell(nb);
            if (cell == '#') // walls
                continue;
            if (visited[nr][nc]) // visited cell
                continue;
            visited[nr][nc] = true; // ecplored
            parent[nr][nc] = cur;   // parent
            st.push(nb);            // push to stack
        }
    }

    if (found)
    {
        // reconstruct path from goal to start using parent array and mark '*' (except S and E)  -- backstracking
        Coordinate cur = goal;
        while (!(cur == start))
        {
            char ch = maze.getCell(cur);
            if (ch != 'S' && ch != 'E') // start/end
            {
                maze.setCell(cur, '*');
            }
            Coordinate p = parent[cur.row][cur.column]; // mobing back
            cur = p;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Solver::writeParentArray(const string &filename) const
{
    if (parent == nullptr) // no sol found
        return false;

    // file output
    ofstream fout(filename);
    if (!fout.is_open()) // validation
    {
        cerr << "Failed to open parent array output file: " << filename << endl;
        return false;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            Coordinate p = parent[i][j];
            if (p.row == -9 && p.column == -9) // wall
            {
                fout << "W";
            }
            else
            {
                fout << "(" << p.row << "," << p.column << ")"; // write the contents
            }
            if (j < cols - 1) // no comma at end
                fout << ",";
        }
        fout << "\n";
    }
    fout.close();
    return true;
}

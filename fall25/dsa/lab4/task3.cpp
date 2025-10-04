#include <iostream>

using namespace std;

// implementation of stack

class Stack
{
private:
    char *arr; // dynamic array
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        arr = new char[capacity];
        top = -1;
    }

    ~Stack() { delete[] arr; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }

    void push(char c)
    {
        if (isFull())
        {
            cout << "Stack overflow!\n";
            return;
        }
        arr[++top] = c;
    }

    char pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow!\n";
            return '\0';
        }
        return arr[top--];
    }

    char peek()
    {
        if (isEmpty())
            return '\0';
        return arr[top];
    }

    void clear() { top = -1; }
};

// required function
bool isBalanced(string expr)
{
    Stack st(expr.length()); // stack size = expression length

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        // push opening braces
        if (ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);
        }
        // check closing braces
        else if (ch == ')' || ch == ']' || ch == '}')
        {
            if (st.isEmpty())
            {
                cout << "Error at character #" << i + 1
                     << " '" << ch << "' - no matching opening.\n";
                return false;
            }

            char top = st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{'))
            {
                cout << "Error at character #" << i + 1
                     << " '" << ch << "' - mismatched.\n";
                return false;
            }
        }
    }

    if (!st.isEmpty())
    {
        cout << "Error: Some opening braces were not closed.\n";
        return false;
    }

    return true;
}

int main()
{
    string expr1 = "1 + 2 * (3 / 4)";
    string expr2 = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10) - 11 + (12*8)] + 14";
    string expr3 = "1 + 2 * [3 * 3 + {4 - 5 (6 (7/8/9) + 10)} - 11 + (12*8) / {13 +13}] + 14";

    cout << expr1 << endl;
    cout << (isBalanced(expr1) ? "This expression is correct.\n\n" : "This expression is NOT correct.\n\n");

    cout << expr2 << endl;
    cout << (isBalanced(expr2) ? "This expression is correct.\n\n" : "This expression is NOT correct.\n\n");

    cout << expr3 << endl;
    cout << (isBalanced(expr3) ? "This expression is correct.\n\n" : "This expression is NOT correct.\n\n");

    return 0;
}
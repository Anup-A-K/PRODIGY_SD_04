#include <iostream>
#include <vector>
using namespace std;

const int N = 9;

void displaygrid(vector<vector<int>> &grid)
{
    for (int i = 0; i < N; i++)
    {
        if (i % 3 == 0 && i != 0)
        {
            cout << "---------------------" << endl;
        }
        for (int j = 0; j < N; j++)
        {
            if (j % 3 == 0 && j != 0)
            {
                cout << "| ";
            }
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafemove(vector<vector<int>> &grid, int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }

    int startrow = row - row % 3;
    int startcol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[i + startrow][j + startcol] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>> &grid)
{
    int row = -1;
    int col = -1;
    bool isEmpty = true;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == 0)
            {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
        {
            break;
        }
    }

    if (isEmpty)
    {
        return true;
    }

    for (int num = 1; num <= N; num++)
    {
        if (isSafemove(grid, row, col, num))
        {
            grid[row][col] = num;
            if (solveSudoku(grid))
            {
                return true;
            }
            else
            {
                grid[row][col] = 0;
            }
        }
    }

    return false;
}

int main()
{
    vector <int> numbers;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int x;
            cin >> x;
            numbers.push_back(x);
        }
    }
    vector<vector<int>> grid(N, vector<int>(N, 0));
    int k = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            grid[i][j] = numbers[k];
            k++;
        }
    }

    if (solveSudoku(grid))
    {
        displaygrid(grid);
    }
    else
    {
        cout << "No solution exists";
    }
    return 0;
}
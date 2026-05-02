#include <iostream>
#include <vector>
using namespace std;

void setRowMinusOne(vector<vector<int>> &matrix, int row)
{
    int m = matrix[0].size();
    for (int j = 0; j < m; j++)
    {
        if (matrix[row][j] != 0)
        {
            matrix[row][j] = -1;
        }
    }
}

void setColumnMinusOne(vector<vector<int>> &matrix, int col)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][col] != 0)
        {
            matrix[i][col] = -1;
        }
    }
}

vector<vector<int>> setZeroTwoDArrayBrut(vector<vector<int>> matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();

    // First pass: find all positions with 0 and mark them as minus one
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                setRowMinusOne(matrix, i);
                setColumnMinusOne(matrix, j);
            }
        }
    }

    // Second pass: set row and column to 0 for each -1 position
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> setZeroTwoDArrayBetter(vector<vector<int>> matrix, int n, int m)
{
    // int n = matrix.size();
    // int m = matrix[1].size();

    vector<int> col(m, 0);
    vector<int> row(n, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                col[j] = 1;
                row[i] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> setZeroTwoDArrayOptimal(vector<vector<int>> matrix, int n, int m)
{
    // int col[m] = [0][..]
    // int row[n] = [..][0]
    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark the i-th row
                matrix[0][j] = 0;

                if (j != 0)
                {
                    matrix[i][0] = 0;
                }
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] =  0;
                }
            }
        }
    }
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }

    return matrix;
}

void printMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> arr = {
        {1, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};

    cout << "Original Matrix:\n";
    printMatrix(arr);

    vector<vector<int>> ans = setZeroTwoDArrayOptimal(arr, 4, 4);

    cout << "\nMatrix after setting zeros:\n";
    printMatrix(ans);

    return 0;
}
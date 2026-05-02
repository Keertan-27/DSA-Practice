#include<iostream>
#include<vector>
using namespace std;


vector<vector<int>> roateMatrixBy90DegreeBrut(vector<vector<int>> matrix)
{
    int n =matrix.size();
    vector<vector<int>> ansMatrix(n, vector<int>(n,0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ansMatrix[j][n-1-i] = matrix[i][j];
        }
    }

    return ansMatrix;
}

vector<vector<int>> roateMatrixBy90DegreeOptimal(vector<vector<int>> matrix)
{
    int n =matrix.size();
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    

    return matrix;
}

void printMatrix(vector<vector<int>> matrix)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<< matrix[i][j] << " ";
        }
        cout<<endl;
    }
    
}
int main()
{
    vector<vector<int>> arr = {
        {1,   2,  3,  4},
        {5,   6,  7,  8},
        {9,  10, 11, 12},
        {13, 14, 15, 16}
    };
    cout<< "Question matrix "<<endl;
    printMatrix(arr);
    
    cout<< endl<< "After rotating matrix by 90˚ clockwise "<<endl;
    vector<vector<int>> ansMatrix = roateMatrixBy90DegreeOptimal(arr);
    printMatrix(ansMatrix);
    return 0;
}
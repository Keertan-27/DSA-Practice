#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int up = INT_MAX;
            int left = INT_MAX;
            if (i > 0)
                up = dp[i - 1][j] + grid[i][j];
            if (j > 0)
                left = dp[i][j-1] + grid[i][j];
            
            dp[i][j] = min(up, left);
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout<< minPathSum(grid);
    return 0;
}
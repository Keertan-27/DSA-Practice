#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int longestRectangle(vector<int> &heights)
{
    int n= heights.size();
    stack<int> st;
    int maxi = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i]))
        {
            int height = heights[st.top()];
            st.pop();
            int nse = i;
            int pse = st.empty() ? -1 : st.top();
            int width = nse - pse - 1;

            maxi = max(maxi, height*width);
        }
        st.push(i);
    }
    return maxi;
}
int maxiRectangleInHistogram(vector<vector<char>> matrix)
{
    if (matrix.empty())
        return 0;
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxArea = 0;
    vector<int> heights(cols, 0);
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == '1')
                heights[j]++;
            else
                heights[j] = 0;
        }
        
        maxArea = max(maxArea, longestRectangle(heights));
    }
    
    return maxArea;
}
int main()
{
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    int ans = maxiRectangleInHistogram(matrix);
    cout << ans;
    return 0;
}
#include<iostream>
#include<vector>
using namespace std;
int mostWaterInContainer(vector<int> heights)
{
    int mostWater = 0;
    int n = heights.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int height = min(heights[i], heights[j]);
            mostWater = max(mostWater, (j-i) * height);
        }
    }
    return mostWater;
    
}
int main()
{
    vector<int> height = {1,1};
    int ans = mostWaterInContainer(height);
    cout<<ans;
    return 0;
}
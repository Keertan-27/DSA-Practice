#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// better solution

// nCr = n! / r! (n-r)!
// Pascal Triangle
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
vector<int> generateRow(int N)
{
    vector<int> ans;
    ans.push_back(1);
    long long result = 1;
    for (int i = 1; i < N; i++)
    {
        result = result * (N - i);
        result = result / i;
        ans.push_back(result);
    }
    return ans;
}


vector<vector<int>> PascalTraingle(int N)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= N; i++)
    {
        ans.push_back(generateRow(i));
    }
    return ans;
}
int main()
{
    int N = 6;
    vector<vector<int>> ans;
    ans = PascalTraingle(N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < (int)ans[i].size(); j++)
        {
            cout<< ans[i][j] << " ";
        }
        cout<<endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
pair<int, int> maxSubarayWithDistinctVal(vector<int> arr, int k)
{
    int distinct = 0;
    int starting = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        unordered_set<int> st;
        for (int j = i; j < i+k; j++)
        {
            st.insert(arr[j]);
        }
        if (st.size() > distinct)
        {
            distinct = st.size();
            starting = i;
        }
    }
    return {distinct, starting};
}
int main()
{
    vector<int> arr = {1, 2, 1, 3, 4, 5, 6, 7};
    pair<int, int> ans = maxSubarayWithDistinctVal(arr, 7);
    cout<<"Max freshness: "<<ans.first<<endl;
    cout<<"First index of it: "<<ans.second;
    return 0;
}
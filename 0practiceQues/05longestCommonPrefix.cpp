#include<iostream>
#include<vector>
#include<string>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    if(strs[0].empty()) return "";
    string pref = strs[0];
    for (int i = 1; i < n; i++)
    {
        string word = strs[i];
        int j = 0;
        while (j< pref.size() && j< word.size() && pref[j] == word[j])
        {
            j++;
        }
        pref = pref.substr(0, j);
    }
    return pref;
}
int main()
{
    vector<string> str = {"flower", "flow", "flight"};
    string ans = longestCommonPrefix(str);
    cout<<ans;
    return 0;
}
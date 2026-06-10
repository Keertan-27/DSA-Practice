#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
bool compare(pair<char,int> &a, pair<char,int> &b)
{
    return a.second > b.second;
}
string sortCharByFrequence(string s)
{
    unordered_map <char, int> mp;
    for(char c : s)
    mp[c]++;
    
    vector<pair<char, int>> v(mp.begin(), mp.end());
    
    sort(v.begin(), v.end(), compare);
    
    string ans = "";
    for(auto &p : v)
    {
        ans += string(p.second, p.first);
    }

    return ans;
}
int main()
{
    string s = "tree";
    string ans = sortCharByFrequence(s);
    cout<<ans;
    return 0;
}
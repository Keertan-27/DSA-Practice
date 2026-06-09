#include <iostream>
#include <string>
using namespace std;
bool rotateString(string s, string goal)
{
    if(s.size() != goal.size())
        return false;
    
    string doubled = s+s;

    return doubled.find(goal) != string::npos;
}

int main()
{
    string s = "abcde";
    string goal = "cdeab";
    bool ans = rotateString(s, goal);
    cout<<ans;
    return 0;
}
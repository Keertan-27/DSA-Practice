#include <iostream>
#include <string>
using namespace std;

int maxNumSubstringContainAllThreeChar(string s)
{
    int lastSeen[3] = {-1, -1, -1};
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        lastSeen[s[i] - 'a'] = i;
        if (lastSeen[0] != -1 & lastSeen[1] != -1 & lastSeen[2] != -1)
        {
            cnt = cnt + (1 + (min({lastSeen[0], lastSeen[1], lastSeen[2]})));
        }
    }
    return cnt;
}
int main()
{
    string s = "bbacba";
    int ans = maxNumSubstringContainAllThreeChar(s);
    cout<<ans;
    return 0;
}
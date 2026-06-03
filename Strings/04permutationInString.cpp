#include <iostream>
#include <string>
using namespace std;

bool checkIsInclusion(string &s1, string &s2)
{
    int n = s1.size();
    int m = s2.size();

    if(n > m)
        return false;

    vector<int> freq1(26,0);
    vector<int> freq2(26,0);

    for (int i = 0; i < n; i++)
    {
        freq1[s1[i] - 'a']++;
    }
    
    for (int i = 0; i < n; i++)
    {
        freq2[s2[i] - 'a']++;
    }
    
    if (freq1 == freq2)
        return true;
    
    int left = 0;
    for (int right = n; right < m; right++)
    {
        freq2[s2[right] - 'a']++;
        freq2[s2[left] - 'a']--;
        left++;

        if (freq1 == freq2)
            return true;
    }
    return false;
    
}
int main()
{
    string s1 = "ab";
    string s2 = "eidbaooo";
    cout<< checkIsInclusion(s1, s2);
    
    return 0;
}
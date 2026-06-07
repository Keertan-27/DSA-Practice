#include<iostream>
#include<string>
using namespace std;

int SubstringExistsInString(string s1, string s2)
{
    for (int i = 0; i < s1.size(); i++)
    {
        int j = 0;
        while (s1[i+j] == s2[j] && j < s2.size())
            j++;
        
        if (j == s2.size())
            return i;
    }
    return -1;
    
}
int main()
{
    string haystack = "sacbutsad";
    string needle = "sad";
    int ans = SubstringExistsInString(haystack, needle);
    cout<<ans;
    return 0;
}
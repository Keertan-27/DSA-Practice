#include<iostream>
#include<string>
using namespace std;

int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i = 0; i<n-m; i++){
            if(haystack.substr(i, m) == needle){
                return i;
            }
        }
        return -1;
    }

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
    string haystack = "sadsadsad";
    string needle = "sad";
    int ans = strStr(haystack, needle);
    cout<<ans;
    return 0;
}
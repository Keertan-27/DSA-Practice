#include<iostream>
#include<string>
#include<vector>
using namespace std;
// for string
string reverseString(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

// for char array
void reverCharArray(vector<char> &charArr){
    int left = 0, right = charArr.size() - 1;
    while (left<right)
    {
        swap(charArr[left++], charArr[right--]);
    }
}

int main()
{
    // char array
    vector<char> charArr = {'H', 'e', 'l', 'l', 'o'};
    reverCharArray(charArr);
    for(auto x : charArr){
        cout<< x << " ";
    }
    cout<<endl;
    // string
    string s = "abcdef";
    string ans = reverseString(s);
    cout<<ans;
    return 0;
}
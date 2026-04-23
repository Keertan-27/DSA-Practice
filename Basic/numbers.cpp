#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int count(int n){
    int count = 0;
    while(n>0){
        count = count +1;
        n =n/10;
    }
    return count;
}

int reverseNum(int n){
    int revNum = 0;
    while(n>0){
        int lastDigit = n%10;
        revNum = (revNum*10) + lastDigit;
        n = n/10;
    }
    return revNum;
}

void palindrome(int n){
    int orgNum =n;
    int revNum = 0;
    while(n>0){
        int lastDigit = n%10;
        revNum = (revNum*10) + lastDigit;
        n = n/10;
    }
    if (revNum == orgNum)
        cout<< "True";
    else cout<< "False";
}

int main()
{
    int n;
    cin>>n;
    palindrome(n);
    
    return 0;
}
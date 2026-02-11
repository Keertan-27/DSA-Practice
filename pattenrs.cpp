#include <iostream>
using namespace std;
void printStarSymmattry(int n)
{
    /*
     ****
     ****
     ****
     ****
     */
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void printIncVerStar(int n)
{
    /*  
     *
     **
     ***
     ****
     */
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<i; j++){
            cout<<"* ";
        }
        cout<< endl;
    }
}

void printIncNumVer(int n){
    /*  
     1
     12
     123
     1234
     */
    for(int i=1; i<=n;i++){
        for(int j=1; j<=i;j++){
            cout<<j<<" ";
        }
        cout<< endl;
    }
}

void printSameNumVer(int n){
    /*  
     1
     22
     333
     4444
     */
    for(int i=1; i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<< endl;
    }
}

void printDecVerStar(int n){
    /*
    * * * * 
    * * * 
    * * 
    * 
    */
    for(int i=n; i>0;i--){
        for(int j=i; j>0;j--){
            cout<<"* ";
        }
        cout<< endl;
    }
}

void printDecVerNum(int n){
    /*
    1 2 3 4 5 6 7 
    1 2 3 4 5 6 
    1 2 3 4 5 
    1 2 3 4 
    1 2 3 
    1 2 
    1 
    */
    for(int i=n; i>0;i--){
        for(int j=1; j<=i;j++){
            cout<<j<< " ";
        }
        cout<< endl;
    }
}
void prinIncNumHorCen(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i;j++){
            cout<<"* ";
        }
        cout<< endl;
    }
}
int main()
{
    int n;
    cin >> n;
    printStarSymmattry(n);
    printIncVerStar(n);
    printIncNumVer(n);
    printSameNumVer(n);
    printDecVerStar(n);
    printDecVerNum(n);
    prinIncNumHorCen(n);
    return 0;
}
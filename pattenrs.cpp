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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void printIncNumVer(int n)
{
    /*
     1
     12
     123
     1234
     */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void printSameNumVer(int n)
{
    /*
     1
     22
     333
     4444
     */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
void printDecVerStar(int n)
{
    /*
     * * * *
     * * *
     * *
     *
     */
    for (int i = n; i > 0; i--)
    {
        for (int j = i; j > 0; j--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
void printDecVerNum(int n)
{
    /*
    1 2 3 4 5 6 7
    1 2 3 4 5 6
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1
    */
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
void prinIncNumHorCen(int n)
{
    /*
     *
     ***
     *****
     *******
     *********
     */
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j >= 1; j--)
        {
            cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++)
        {
            cout << "*";
        }
        for (int l = n - i; l >= 1; l--)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void prinDecNumHorCen(int n)
{

    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 2 * i - 1; k >= 1; k--)
        {
            cout << "*";
        }
        for (int l = 1; l <= n - i; l++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void printIncDecSumHorCen(int n)
{
    /*
     *
     ***
     *****
     *******
     *********
     *********
     *******
     *****
     ***
     *
     */
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j >= 1; j--)
        {
            cout << " ";
        }
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        for (int j = n - i; j >= 1; j--)
        {
            cout << " ";
        }
        cout << endl;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int j = 2 * i - 1; j >= 1; j--)
        {
            cout << "*";
        }
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << endl;
    }
}
void halfVerIncDecPattern(int n)
{
    /*
     *
     **
     ***
     ****
     *****
     ****
     ***
     **
     *
     */
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void halfVerIncDecPattern2(int n)
{
    /*
     *
     **
     ***
     ****
     *****
     ****
     ***
     **
     *
     */
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int star = i;
        if (i > n)
            star = 2 * n - i;
        for (int j = 1; j <= star; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
void alterBinNumIncVertPattern(int n)
{
    /*
    1
    01
    101
    0101
    10101
    010101
    1010101
    */
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 1; j <= i; j++)
            {
                if (j % 2 == 0)
                    cout << "1";
                else
                    cout << "0";
            }
            cout << endl;
        }
        else
        {
            for (int j = 1; j <= i; j++)
            {
                if (j % 2 == 0)
                    cout << "0";
                else
                    cout << "1";
            }
            cout << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    // printStarSymmattry(n);
    // printIncVerStar(n);
    // printIncNumVer(n);
    // printSameNumVer(n);
    // printDecVerStar(n);
    // printDecVerNum(n);
    // prinIncNumHorCen(n);
    // prinDecNumHorCen(n);
    // printIncDecSumHorCen(n);
    // halfVerIncDecPattern(n);
    // halfVerIncDecPattern2(n);
    alterBinNumIncVertPattern(n);
    return 0;
}
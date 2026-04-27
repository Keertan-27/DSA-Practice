#include <iostream>
#include <vector>
#include <set>
using namespace std;
//
vector<int> unionArraySet(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();

    set<int> st;
    for (int i = 0; i < n1; i++)
    {
        st.insert(a[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        st.insert(b[i]);
    }
    vector<int> temp;
    for (int x : st)
    {
        temp.push_back(x);
    }
    return temp;
}

vector<int> unionArrayPointer(vector<int> a, vector<int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    vector<int> temp;

    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (temp.size() == 0 || temp.back() != a[i])
            {
                temp.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (temp.size() == 0 || temp.back() != b[j])
            {
                temp.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (temp.size() == 0 || temp.back() != a[i])
        {
            temp.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (temp.size() == 0 || temp.back() != b[j])
        {
            temp.push_back(b[j]);
        }
        j++;
    }
    return temp;
}

int main()
{
    vector<int> a = {1, 2, 4, 6, 7, 9};
    vector<int> b = {2, 4, 5, 6, 7, 8};
    vector<int> ans = unionArrayPointer(a, b);

    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

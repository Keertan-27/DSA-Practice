#include<iostream>
#include<vector>
#include<set>
using namespace std;
// brutforce solution
vector<int> unionArray(int a[], int n1, int b[], int n2)
{
    set<int> st;
    for(int i=0; i<n1; i++){
        st.insert(a[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        st.insert(b[i]);
    }
    vector<int> temp;
    for(auto it : st){
        temp.push_back(it);
    }
    return temp;
}

// optimal solution
vector<int> unionArr1(int a[], int n1, int b[], int n2)
{
    vector<int> ans;
    int i = 0;
    int j = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (ans.size() == 0 || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != b[j])
            {
                ans.push_back(b[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (ans.size() == 0 || ans.back() != a[i])
        {
            ans.push_back(a[i]);
        }
        i++;
    }

    while (j < n2)
    {
        if (ans.size() == 0 || ans.back() != b[j])
        {
            ans.push_back(b[j]);
        }
        j++;
    }

    return ans;
}
int main()
{
    int a[6] = {1,2,2,3,5,7};
    int b[5] = {1,4,5,6,7};

    vector<int> ans = unionArr1(a, 6, b, 5);
    for (int x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
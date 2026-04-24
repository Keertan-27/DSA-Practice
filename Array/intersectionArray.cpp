#include<iostream>
#include<vector>
using namespace std;

vector <int> intersectionArrayBrut(vector <int> a, vector <int> b)
{
    int n1 = a.size();
    int n2 = b.size();
    vector <int> ans;
    vector<int> vis(n2, 0);

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j] && vis[j] == 0)
            {
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
            if (b[j] > a[i]) break;
        }
    }
    return ans;
}

vector <int> intersectionArrayPointer(vector <int> a, vector <int> b)
{
    int n1=a.size();
    int n2=b.size();
    vector<int> ans;

    int i = 0;
    int j = 0;
    while (i<n1 && j<n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if(a[i] > b[j]){
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    
    return ans;
}
int main()
{
    vector <int> a = {1,1,2,3,5,5,6,7};
    vector <int> b = {1,2,2,3,4,5,6};
    vector <int> ans = intersectionArrayPointer(a, b);

    for (int x : ans)
    {
        cout<< x<< " ";
    }
    cout<<endl;
    
    return 0;
}
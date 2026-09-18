#include<iostream>
#include<vector>
using namespace std;
int maxItem(vector<pair<int,string>> &item, int buget)
{
    int n = item.size();
    vector<pair<int, int>> newItem;
    int maxPurchase = 0;
    for (int i = 0; i < n; i++)
    {
        if (item[i].second == "pack of two")
        {
            item[i].first = (item[i].first)*2;
            item[i].second = 2;
        }else{
            item[i].second = 1;
        }
    }

    for (int i = 0; i < 2*n-1; i++)
    {
        int newBuget = buget;
        int purchase = 0;
        for (int j = i; j < 2*n-1; j++)
        {
            if (item[j].first > newBuget)
            {
                break;
            }
            else{
                purchase += item[j].second;
                newBuget -= item[j].first;
            }
        }
        maxPurchase = max(maxPurchase, purchase);
    }
    
return maxPurchase;
}
int main()
{
    vector<pair<int,string>> item = {{2,"single"}, {3, "pack of two"}, {6,"single"}};
    int buget = 8;
    int ans = maxItem(item, buget);
    cout<<ans;
    return 0;
}
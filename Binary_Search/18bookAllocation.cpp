#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int numStudentCanfill(vector<int> pages, int value)
{
    int studentCnt = 1;
    int sum = 0;
    for (int i = 0; i < pages.size(); i++)
    {
        if(sum + pages[i] > value){
            studentCnt++;
            sum = pages[i];
        }
        else{
            sum += pages[i];
        }
    }
    return studentCnt;
}
int bookAllocation(vector<int> pages, int students)
{
    int low = *max_element(pages.begin(), pages.end());
    int high = accumulate(pages.begin(), pages.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int studentCnt = numStudentCanfill(pages, mid);
        if (studentCnt <= students)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    vector<int> pages = {25, 46, 28, 49, 24};
    int students = 4;
    int ans = bookAllocation(pages, students);
    cout<<ans;
    return 0;
}
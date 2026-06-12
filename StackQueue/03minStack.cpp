#include<iostream>
#include<stack>
using namespace std;
class MinStack
{
public:
    stack <pair<int, int>> st;

    void pushfun(int val)
    {
        if(st.empty()){
            st.push({val, val});
        }
        else
            st.push({val, min(val, st.top().second)});
    }

    void popfun(){
        if(!st.empty())
            st.pop();
    }
    int getMin()
    {
        return st.top().second;
    }

    int topfun()
    {
        return st.top().first;
    }
};
int main()
{
    MinStack st;
    st.pushfun(14);
    st.pushfun(4);
    st.pushfun(10);
    st.pushfun(6);
    st.pushfun(2);
    cout << "Top = " << st.topfun() << endl;
    cout << "Min = " << st.getMin() << endl;
    st.popfun();

    cout << "Top = " << st.topfun() << endl;
    cout << "Min = " << st.getMin() << endl;
    return 0;
}
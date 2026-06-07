#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char> &chars)
{
    int idx = 0;
    int i = 0;
    while (i < chars.size())
    {
        int cnt = 0;
        char ch = chars[i];
        while (i < chars.size() && chars[i] == ch)
        {
            cnt++;
            i++;
        }

        chars[idx++] = ch;
        if (cnt > 1)
        {
            string strCnt = to_string(cnt);
            for (auto c : strCnt)
                chars[idx++] = c;
        }
    }
    return idx;
}
int main()
{
    vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'c', 'c', 'c', 'c'};
    int charLen = compress(chars);
    cout << "Lenght: " << charLen << endl;

    for (int i = 0; i < charLen; i++)
    {
        cout << chars[i] << " ";
    }
    return 0;
}
#include <iostream>

using namespace std;

string runLengthEncoding(string str)
{
    int n = str.size();
    if(n == 0)
        return "";

    string ans = "";
    char c = str[0];
    int cnt = 0;
    for (int i = 0; i < n;++i)
    {
        if(str[i] == c)
            ++cnt;
        else
        {
            ans += to_string(cnt) + c;
            cnt = 1;
            c = str[i];
        }
        if(cnt >= 10)
        {
            ans += to_string(9) + c;
            cnt = 1;
        }
    }
    ans += to_string(cnt) + c;
    return ans;
}
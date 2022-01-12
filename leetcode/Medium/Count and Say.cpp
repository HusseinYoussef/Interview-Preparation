#include <iostream>

using namespace std;

string countAndSay(int n)
{
    if(n == 1)
        return "1";

    string s = countAndSay(n - 1);
    string ans = "";
    int pre = s[0] - '0';
    int cnt = 1;
    for (int i = 1; i < s.size();++i)
    {
        if(pre == s[i]-'0')
            ++cnt;
        else
        {
            ans += to_string(cnt) + to_string(pre);
            pre = s[i] - '0';
            cnt = 1;
        }
    }
    ans += to_string(cnt) + to_string(pre);
    return ans;
}
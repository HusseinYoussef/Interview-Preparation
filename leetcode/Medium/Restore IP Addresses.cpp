#include <iostream>
#include <vector>

using namespace std;

void rec(vector<string> &ips, string &s, string ip, int dots, int idx=0)
{
    if(dots == 4 && idx == s.size())
    {
        ip.pop_back();
        ips.push_back(ip);
        return;
    }

    int num = 0;
    for (int i = idx; i < s.size();++i)
    {
        num = num * 10 + (s[i] - '0');
        // all upcoming strs are invalid
        if(num > 255 || (s[idx] == '0' && i != idx))
            return;
        ip.push_back(s[i]);
        if(num >= 0 && num <= 255 && dots < 4)
        {
            ip.push_back('.');
            rec(ips, s, ip, dots + 1, i + 1);
            ip.pop_back();
        }
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> ips;
    rec(ips, s, "", 0, 0);
    return ips;
}
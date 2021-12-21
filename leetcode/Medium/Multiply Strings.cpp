#include <iostream>
#include <vector>

using namespace std;

string add(string s, string t)
{
    int carry = 0;
    string ans = "";
    for (int i = s.size() - 1, j = t.size() - 1; i >= 0 || j >= 0; --i, --j)
    {
        int d1, d2;
        d1 = i >= 0 ? s[i] - '0' : 0;
        d2 = j >= 0 ? t[j] - '0' : 0;
        int sum = d1 + d2 + carry;
        carry = sum >= 10;
        ans = to_string(sum % 10) + ans;
    }
    if(carry)
        ans = to_string(1) + ans;
    return ans;
}

string multiply(string num1, string num2)
{
    string ans = "", pre = "";
    int carry = 0;
    for (int i = num2.size() - 1; i >= 0;--i)
    {
        int d2 = num2[i] - '0';
        carry = 0;
        ans = "";
        for (int j = num1.size() - 1; j >= 0;--j)
        {
            int d1 = num1[j] - '0';
            int mul = d1 * d2 + carry;
            carry = mul / 10;
            ans = to_string(mul % 10) + ans;
        }
        if(carry)
            ans = to_string(carry) + ans;
        if(pre.size())
        {
            string z = "";
            for (int j = 0; j < num2.size() - 1-i;++j)
                z += '0';
            ans += z;
            pre = add(pre, ans);
        }
        else
            pre = ans;
    }
    int idx = 0;
    for (; idx < pre.size(); ++idx)
    {
        if(pre[idx] != '0')
            break;
    }
    // 0000
    return pre.substr(min(idx, (int)pre.size() - 1));
}
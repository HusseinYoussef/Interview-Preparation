#include <iostream>
#include <algorithm>

using namespace std;

string getValue(int sum)
{
    string ans = "";
    if(sum == 10)
        ans += "a";
    else if(sum == 11)
        ans += "b";
    else if(sum == 12)
        ans += "c";
    else if(sum == 13)
        ans += "d";
    else if(sum == 14)
        ans += "e";
    else if(sum == 15)
        ans += "f";
    else
        ans += to_string(sum);
    return ans;
}

string toHex(int num)
{
    int sum = 0;
    int c = 1;
    string ans = "";
    int bits = 1;
    while(bits <= 32)
    {
        sum += c * (num & 1);
        c *= 2;
        if(c > 8)
        {
            ans += getValue(sum);
            c = 1;
            sum = 0;
        }
        num >>= 1;
        bits++;
    }
    if(sum)
        ans += getValue(sum);
    reverse(ans.begin(), ans.end());
    int i;
    // '000001a'  '0'  find first non-zero char keeping ans length >= 1
    for (i = 0; i < ans.size()-1;++i)
    {
        if(ans[i] != '0')
            break;
    }
    return ans.substr(i);
}

int main()
{
    cout << toHex(26);
    return 0;
}
#include <iostream>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    int n = a.size(), m = b.size();
    int i = n - 1, j = m - 1, carry = 0;
    string ans = "";
    while(i >= 0 || j >= 0)
    {
        int d1 = 0, d2 = 0;
        if(i >= 0)
            d1 = a[i--] - '0';
        if(j >= 0)
            d2 = b[j--] - '0';
        int sum = d1 + d2 + carry;
        carry = sum > 1;
        ans.push_back((sum % 2) + '0');
    }
    if(carry)
        ans.push_back('1');
    reverse(ans.begin(), ans.end());
    return ans;
}
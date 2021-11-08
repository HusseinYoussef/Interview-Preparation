#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addBinary(string a, string b)
{
    int i = a.size() - 1, j = b.size() - 1;
    bool carry = 0;
    string ans = "";
    while(i >= 0 || j >= 0)
    {
        int aval = (i >= 0) ? (a[i] - '0') : 0;
        int bval = (j >= 0) ? (b[j] - '0') : 0;
        int sum = (aval + bval + carry);
        if(sum >= 2)
        {
            ans += (sum % 2) + '0';
            carry = 1;
        }
        else
        {
            int val = aval + bval + carry;
            ans += val + '0';
            carry = 0;
        }
        --i, --j;
    }
    if(carry)
        ans += '1';
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << addBinary("11", "110");
    return 0;
}
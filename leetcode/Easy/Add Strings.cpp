#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string addStrings(string num1, string num2)
{
    bool c = 0;
    string ans = "";
    for (int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; --i,--j)
    {
        int l = i >= 0 ? num1[i] - '0' : 0;
        int r = j >= 0 ? num2[j] - '0' : 0;

        ans += to_string((l + r + c) % 10);
        if(l + r + c > 9)
            c = 1;
        else
            c = 0;
    }
    if(c)
        ans += "1";
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    return 0;
}
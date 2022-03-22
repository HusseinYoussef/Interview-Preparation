#include <iostream>

using namespace std;

string getSmallestString(int n, int k)
{
    string ans = "";
    int lft = 0;
    for(int i = 0;i<n;++i)
    {
        lft = (n-i-1)*26;
        if(lft >= k)
        {
            ans.push_back('a');
            --k;
        }
        else
        {
            ans.push_back(k-lft-1 + 'a');
            k = lft;
        }
    }
    return ans;
}

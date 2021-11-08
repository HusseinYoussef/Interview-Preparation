#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool ok(vector<string>& strs, int mid)
{
    string str0 = strs[0].substr(0, mid);
    for (int i = 1; i < strs.size();++i)
    {
        string str1 = strs[i].substr(0, mid);
        if(str1 != str0)
            return false;
    }
    return true;
}

string longestCommonPrefix(vector<string>& strs)
{
    // O(N * log m) => N ~ sum of all characters in all strings, m ~ min length of a string

    // int mn = 1000;
    // for (int i = 0; i < strs.size();++i)
    // {
    //     mn = min(mn, (int)strs[i].size());
    // }
    // int l = 1, r = mn+1, mid;
    // while(l < r)
    // {
    //     mid = l + (r - l) / 2;
    //     if(ok(strs, mid))
    //         l = mid + 1;
    //     else
    //         r = mid;
    // }
    // l -= 1;
    // if(l == 0)
    //     return "";
    // else
    //     return strs[0].substr(0, l);

    // O(N) => N ~ sum of all characters in all strings
    
    string pre = strs[0];
    for (int i = 1; i < strs.size();++i)
    {
        while(strs[i].find(pre) != 0)
        {
            pre = pre.substr(0, pre.size() - 1);
        }
    }
    return pre;
}
int main()
{
    vector<string> vec = {"hello","hello", "k"};
    cout << longestCommonPrefix(vec);
    return 0;
}
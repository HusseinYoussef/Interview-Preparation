#include <iostream>
#include <vector>

using namespace std;

bool checkPalindrome(string &s, int l, int r)
{
    while(l < r)
    {
        if(s[l] != s[r])
            return false;
        ++l, --r;
    }
    return true;
}

void rec(vector<vector<string>> &ans, string &s, vector<string> &strs, int start)
{
    if(start == s.size())
    {
        ans.push_back(strs);
        return;
    }

    for(int i=start;i<s.size();++i)
    {
        if(checkPalindrome(s, start, i))
        {
            strs.push_back(s.substr(start, i-start+1));
            rec(ans, s, strs, i+1);
            strs.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string>strs;
    rec(ans, s, strs, 0);
    return ans;
}

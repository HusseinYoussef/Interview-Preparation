#include <iostream>
#include <vector>

using namespace std;

void rec(vector<string> &ans, string &s, int idx)
{
    if(idx == s.size())
    {
        ans.push_back(s);
        return;
    }

    rec(ans, s, idx + 1);
    if(isalpha(s[idx]))
    {
        if(islower(s[idx]))
            s[idx] = toupper(s[idx]);
        else
            s[idx] = tolower(s[idx]);
        rec(ans, s, idx + 1);
    }
}

vector<string> letterCasePermutation(string s)
{
    vector<string> ans;
    rec(ans, s, 0);
    return ans;
}
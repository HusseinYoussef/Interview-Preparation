#include <iostream>
#include <vector>

using namespace std;

string arr[10];
vector<string> ans;

void rec(string &s, string comb, int idx)
{
    if(idx == s.size())
    {
        if(!comb.empty())
            ans.push_back(comb);
        return;
    }
    for (int i = 0; i < arr[s[idx] - '0'].size();++i)
    {
        rec(s, comb + arr[s[idx] - '0'][i], idx + 1);
    }
}

vector<string> letterCombinations(string digits)
{
    arr[2] = "abc", arr[3] = "def", arr[4] = "ghi", arr[5] = "jkl", arr[6] = "mno", arr[7] = "pqrs", arr[8] = "tuv", arr[9] = "wxyz";
    rec(digits, "", 0);
    return ans;
}
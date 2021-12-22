#include <iostream>
#include <vector>

using namespace std;

vector<string> ans;
void solve(string s, int openBracket, int closedBracket)
{
    if(openBracket == 0 && closedBracket == 0)
    {
        ans.push_back(s);
        return;
    }
    if(openBracket)
        solve(s + "(", openBracket - 1, closedBracket);
    if(closedBracket > openBracket)
        solve(s + ")", openBracket, closedBracket - 1);
}

vector<string> generateParenthesis(int n)
{
    solve("(", n-1, n);
    return ans;
}
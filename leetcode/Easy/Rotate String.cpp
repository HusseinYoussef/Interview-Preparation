#include <iostream>
#include <string>

using namespace std;

bool rotateString(string s, string goal)
{
    if(goal.size() != s.size())
        return false;
    string ans = s + s;
    return ans.find(goal) != -1;
}
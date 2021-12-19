#include <iostream>
#include <vector>

using namespace std;

vector<string> removeComments(vector<string>& source)
{
    vector<string> ans;
    string tmp = "";
    bool block = 0, line = 0;
    for (int i = 0; i < source.size();++i)
    {
        int n = source[i].size();
        for (int j = 0; j < n;++j)
        {
            if(j + 1 < n && source[i][j] == '/' && source[i][j+1] == '/' && block == 0)
            {
                line = 1;
                ++j;
                continue;
            }
            if(j + 1 < n && source[i][j] == '/' && source[i][j+1] == '*' && line == 0 && block == 0)
            {
                block = 1;
                j++;
                continue;
            }
            else if(j + 1 < n && source[i][j] == '*' && source[i][j+1] == '/' && block == 1)
            {
                block = 0;
                j++;
                continue;
            }
            if(block == 0 && line == 0)
            {
                tmp += source[i][j];
            }
        }
        line = 0;
        if(tmp.size() && block == 0 && line == 0)
        {
            ans.push_back(tmp);
            tmp = "";
        }
    }
    return ans;
}
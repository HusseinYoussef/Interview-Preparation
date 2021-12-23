#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<string> commonChars(vector<string>& words)
{
    int n = words.size();
    vector<string> ans;
    for (int k = 0; k < 26;++k)
    {
        char c = 'a' + k;
        int common = INT_MAX;
        for (int i = 0; i < n;++i)
        {
            int cnt = 0;
            for (int j = 0; j < words[i].size();++j)
            {
                cnt += c == words[i][j];
            }
            common = min(common, cnt);
            if(cnt == 0)
                break;
        }
        for (int j = 0; j < common;++j)
            ans.push_back(string(1, c));
    }
    return ans;
}
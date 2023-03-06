#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string encode(vector<string> &strs)
    {
        int n = strs.size();
        string ans = "";
        for(int i  = 0;i<n;++i)
            ans += to_string(strs[i].size()) + "#" + strs[i];

        return ans;
    }

    vector<string> decode(string &str)
    {
        vector<string> ans;
        int i = 0;
        string num = "";
        while(i < str.size())
        {
            if(str[i] == '#')
            {
                int wordLen = stoi(num);
                num = "";
                ans.push_back(str.substr(i+1, wordLen));
                i += wordLen + 1;
            }
            else
            {
                num += str[i];
                i++;
            }
        }
        return ans;
    }
};

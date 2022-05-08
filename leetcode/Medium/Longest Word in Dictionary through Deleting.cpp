#include <iostream>
#include <vector>

using namespace std;

string findLongestWord(string s, vector<string> dictionary)
{
    string ans = "";
    for (int i = 0; i < dictionary.size();++i)
    {
        // check if dictionary[i] is subsequence of s
        int j = 0, k = 0;
        while(j < s.size() && k < dictionary[i].size())
        {
            if(s[j] == dictionary[i][k])
                ++k;
            ++j;
        }
        if(k == dictionary[i].size())
        {
            if(dictionary[i].size() > ans.size() || (dictionary[i].size() == ans.size() && dictionary[i] < ans))
                ans = dictionary[i];
        }
    }
    return ans;
}
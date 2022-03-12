#include <iostream>
#include <vector>

using namespace std;

int shortestWordDistance(vector<string> &words, string &word1, string &word2)
{
    int n = words.size();
    int ans = 1e7;
    vector<int> idx(2, -1);
    bool f = 0;
    for (int i = 0; i < n;++i)
    {
        if(word1 == word2 && word1 == words[i])
        {
            idx[f] = i;
            f = !f;
        }
        else if(words[i] == word1)
            idx[0] = i;
        else if(words[i] == word2)
            idx[1] = i;

        if(idx[0] != -1 && idx[1] != -1)
            ans = min(ans, abs(idx[0] - idx[1]));
    }
    return ans;
}
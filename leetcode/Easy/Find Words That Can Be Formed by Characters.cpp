#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int countCharacters(vector<string>& words, string chars)
{
    int ans = 0;
    int freq1[26], freq2[26];
    memset(freq1,0, sizeof(freq1));
    for(int i=0;i<chars.size();++i)
        freq1[chars[i]-'a']++;
    for(int i =0;i<words.size();++i)
    {
        bool f = 1;
        memset(freq2,0,sizeof(freq2));
        for(int j = 0;j<words[i].size();++j)
            freq2[words[i][j]-'a']++;
        for(int j = 0;j<26;++j)
        {
            if(freq2[j] > freq1[j])
            {
                f = 0;
                break;
            }
        }
        if(f)
            ans += words[i].size();
    }
    return ans;
}

#include <iostream>
#include <vector>

using namespace std;

bool checkWords(int* lfreq, string &s)
{
    int rfreq[26];
    memset(rfreq, 0, sizeof(rfreq));
    for(int j =0;j<s.size();++j)
    {
        if(isalpha(s[j]))
            rfreq[tolower(s[j])-'a']++;
    }
    for(int j=0;j<26;++j)
    {
        if(lfreq[j] > rfreq[j])
            return false;
    }
    return true;
}

string shortestCompletingWord(string licensePlate, vector<string>& words)
{
    int lfreq[26];
    int mn = 20;
    memset(lfreq, 0, sizeof(lfreq));
    for(int i =0;i<licensePlate.size();++i)
    {
        if(isalpha(licensePlate[i]))
            lfreq[tolower(licensePlate[i])-'a']++;
    }
    for(int i =0;i<words.size();++i)
    {   
        if(checkWords(lfreq, words[i]))
            mn = min(mn, (int)words[i].size());
    }
    string ans;
    for(int i=0;i<words.size();++i)
    {
        if(words[i].size() == mn && checkWords(lfreq, words[i]))
        {
            ans = words[i];
            break;
        }
    }
    return ans;
}

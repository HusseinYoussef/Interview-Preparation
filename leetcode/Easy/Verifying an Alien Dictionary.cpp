#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool check(string a, string b, int pos[])
{
    for (int i = 0; i < min(a.size(), b.size());++i)
    {
        if(pos[a[i] - 'a'] < pos[b[i] - 'a'])
            return true;
        if(pos[a[i] - 'a'] > pos[b[i] - 'a'])
            return false;
    }
    return a.size() <= b.size();
}

bool isAlienSorted(vector<string>& words, string order)
{
    int pos[30];
    memset(pos, 0, sizeof(pos));
    for (int i = 0; i < order.size();++i)
        pos[order[i] - 'a'] = i;

    for (int i = 0, j = 1; j < words.size(); ++i, ++j)
    {
        if(!check(words[i], words[j], pos))
            return false;
    }
    return true;
}

int main()
{
    vector<string> vec = {"word","world"};
    cout << isAlienSorted(vec, "worldabcefghijkmnpqstuvxyz");
    return 0;
}
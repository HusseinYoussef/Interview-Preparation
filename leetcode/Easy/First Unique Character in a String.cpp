#include <iostream>
#include <vector>

using namespace std;

int firstUniqChar(string s)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size();++i)
    {
        if(freq[s[i]-'a'] == 0)
            freq[s[i] - 'a'] = 1;
        else
            freq[s[i] - 'a'] = -1;
    }
    int ans = -1;
    for (int i = 0; i < s.size();++i)
    {
        if(freq[s[i]-'a'] == 1)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    return 0;
}
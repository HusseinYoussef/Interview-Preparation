#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRepeatedDnaSequences(string s)
{
    int n = s.size();
    unordered_map<string, int>mp;
    vector<string>ans;
    for(int i = 0;i<=n-10;++i)
    {
        string str = s.substr(i, 10);
        if(mp[str] == 1)
            ans.push_back(str);
        ++mp[str];
    }
    return ans;
}

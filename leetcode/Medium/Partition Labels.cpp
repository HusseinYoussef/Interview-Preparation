#include <iostream>
#include <vector>

using namespace std;

vector<int> partitionLabels(string s)
{
    int n = s.size();
    vector<int> r(26, 0);

    for(int i = 0;i<n;++i)
        r[s[i]-'a'] = i;

    vector<int>ans;
    for(int i = 0, j;i<n;)
    {
        int ridx = r[s[i]-'a'];
        for(j = i; j<=ridx;++j)
        {
            ridx = max(ridx, r[s[j]-'a']);
        }
        ans.push_back(j-i);
        i = j;
    }
   return ans;
}

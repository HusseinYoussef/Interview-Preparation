#include <iostream>

using namespace std;

string removeOccurrences(string s, string part)
{
    int n = s.size(), m = part.size();
    string ans = "";
    for(int i =0;i<n;++i)
    {
        ans.push_back(s[i]);
        int sz = ans.size();
        if(s[i] == part[m-1] && sz >= m)
        {
            bool f = 1;
            for(int j =0;j<m;++j)
            {
                if(ans[sz-1-j] != part[m-1-j])
                {
                    f = 0;
                    break;
                }
            }
            if(f)
            {
                for(int j=0;j<m;++j)
                    ans.pop_back();
            }
        }
    }
    return ans;
}

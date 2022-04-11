#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<string>& words)
{
    int n = words.size();
    vector<int> charbits(n, 0);

    for(int i = 0;i<n;++i)
    {
        for(int j =0 ;j<words[i].size();++j)
        {
            charbits[i] |= 1 << (words[i][j] - 'a');
        }
    }

    int mx = 0;
    for(int i = 0;i<n;++i)
    {
        for(int j = i+1;j<n;++j)
        {
            if((charbits[i] & charbits[j]) == 0)
               mx = max(mx, (int)words[i].size() * (int)words[j].size()); 
        }
    }
    return mx;
}

#include <string>

using namespace std;

int partitionString(string s)
{
    int n = s.size();
    int msk = 0;

    int ans = 1;
    for(int i = 0;i<n;++i)
    {
        int idx = 1 << (s[i] - 'a');
        if (msk & idx)
        {
            ++ans;
            msk = 0;
        }
        msk |= idx;
    }
    return ans;
}

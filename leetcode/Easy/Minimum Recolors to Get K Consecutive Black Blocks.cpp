#include <string>

using namespace std;

int minimumRecolors(string blocks, int k) 
{
    // get min number of whites in sliding window of size k
    int n = blocks.size();
    int ans = INT_MAX;

    int cnt = 0; // whites count
    for(int i = 0;i<n;++i)
    {
        if (i >= k)
            cnt -= blocks[i-k] == 'W';
        cnt += blocks[i] == 'W';

        if (i >= k-1)
            ans = min(ans, cnt);
    }
    return ans;
}

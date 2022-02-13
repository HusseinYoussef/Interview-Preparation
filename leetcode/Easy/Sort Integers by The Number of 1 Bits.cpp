#include <vector>

using namespace std;

bool static cmp(int a, int b)
{
    int t1 = a, t2 = b;
    int cnt1 = 0, cnt2 = 0;
    while(t1)
    {
        cnt1 += t1&1;
        t1 >>= 1;
    }
    while(t2)
    {
        cnt2 += t2&1;
        t2 >>= 1;
    }
    if(cnt1 != cnt2)
        return cnt1 < cnt2;
    return a < b;
}

vector<int> sortByBits(vector<int>& arr)
{
    sort(arr.begin(), arr.end(), cmp);
    return arr;
}

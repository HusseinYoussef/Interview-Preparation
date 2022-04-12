#include <vector>

using namespace std;

// traverse bits from left or right doesn't matter
int msk = 0;
void rec(vector<int> &ans, int idx, int n)
{
    if(idx == n)
    {
        ans.push_back(msk);
        return;
    }

    rec(ans, idx + 1, n);
    msk ^= 1 << idx;
    rec(ans, idx + 1, n);
}

vector<int> grayCode(int n)
{
    vector<int> ans;
    rec(ans, 0, n);
    return ans;
}
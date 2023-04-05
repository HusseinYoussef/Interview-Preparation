#include <vector>

using namespace std;

int BS(vector<int>& v, long long target)
{
    int n = v.size();
    int l = -1, r = n, mid;
    while (r - l > 1)
    {
        mid = l + (r-l) / 2;
        if (v[mid] >= target)
            r = mid;
        else
            l = mid;
    }
    return r;
}

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
{
    int n = spells.size(), m = potions.size();

    sort(potions.begin(), potions.end());

    vector<int> ans;
    for(int i = 0;i<n;++i)
    {
        long long target = ceil(success * 1.0 / spells[i]);
        int idx = BS(potions, target);

        ans.push_back(m - idx); 
    }

    return ans;
}

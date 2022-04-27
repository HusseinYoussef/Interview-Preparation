#include <vector>
#include <unordered_map>

using namespace std;

vector<int> arrIntersection(vector<int>& arr1, vector<int>& arr2)
{
    int n = arr1.size(), m = arr2.size();
    vector<int> ans;
    unordered_map<int, bool> mp;
    for (int i = 0; i < n;++i)
        mp[arr1[i]] = 1;

    for (int i = 0; i < m;++i)
    {
        if(mp[arr2[i]])
        {
            ans.push_back(arr2[i]);
            mp[arr2[i]] = 0;
        }
    }
    return ans;
}
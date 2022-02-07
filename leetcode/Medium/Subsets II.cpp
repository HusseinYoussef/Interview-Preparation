#include <vector>

using namespace std;

void rec(vector<vector<int>> &ans, vector<int> &nums, vector<int> &freq, vector<int> &st, int idx)
{
    if(idx == nums.size())
    {
        ans.push_back(st);
        return;
    }

    rec(ans, nums, freq, st, idx+1);
    st.push_back(nums[idx]-10);
    freq[nums[idx]]--;
    rec(ans, nums, freq, st, idx+(freq[nums[idx]]==0));
    st.pop_back();
    freq[nums[idx]]++;
}

vector<vector<int>> subsetsWithDup(vector<int>& nums)
{
    int n = nums.size();
    vector<int> freq(22, 0);
    for(int i = 0;i<n;++i)
        ++freq[nums[i]+10];

    nums.clear();
    for(int i=0;i<=20;++i)
        if(freq[i])
            nums.push_back(i);
    vector<vector<int>> ans;
    vector<int> st;
    rec(ans, nums, freq, st, 0);
    return ans;
}

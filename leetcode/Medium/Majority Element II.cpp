#include <iostream>
#include <vector>

using namespace std;

vector<int> majorityElement(vector<int>& nums)
{
    // Boyer Moore
    int n = nums.size();
    int cnt1 = 0, cand1 = 0, cnt2 = 0, cand2 = 1;
    for (int i = 0; i < n;++i)
    {
        if(nums[i] == cand1)
            ++cnt1;
        else if(nums[i] == cand2)
            ++cnt2;
        else if(cnt1 == 0)
            cnt1 = 1, cand1 = nums[i];
        else if(cnt2 == 0)
            cnt2 = 1, cand2 = nums[i];
        else
            --cnt1, --cnt2;
    }
    vector<int> ans;
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n;++i)
    {
        cnt1 += nums[i] == cand1;
        cnt2 += nums[i] == cand2;
    }
    if(cnt1 > n/3)
        ans.push_back(cand1);
    if(cnt2 > n/3)
        ans.push_back(cand2);
    return ans;
}
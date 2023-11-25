#include <vector>

using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int>& nums)
{
    int n = nums.size();
    vector<int> rsum(n, 0);
    rsum[n-1] = nums[n-1];
    for (int i = n-2;i>=0;--i)
    {
        rsum[i] += nums[i] + rsum[i+1]; 
    }

    vector<int> ans;
    int lsum = 0;
    for(int i =0;i<n;++i)
    {
        lsum += nums[i];

        int sum = (i+1)*nums[i] - lsum + -1*(n-i)*nums[i] + rsum[i];
        ans.push_back(sum);
    }
    return ans;
}

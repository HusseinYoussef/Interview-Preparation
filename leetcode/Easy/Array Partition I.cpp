#include <iostream>
#include <vector>

using namespace std;
int arrayPairSum(vector<int>& nums)
{
//  sort(nums.begin(), nums.end());
//  int ans=0;
//  for(int i=0;i<nums.size();i+=2)
//  {
//      ans+=nums[i];
//  }
//  return ans;

    int arr[20004];
    memset(arr, 0, sizeof(arr));
    for(int i=0;i<nums.size();++i)
        arr[nums[i]+10000]++;
    int idx=0, ans=0;
    for(int i =0;i<20004;++i)
    {
        for(int j =0;j<arr[i];++j)
            nums[idx++] = i-10000;
    }
    for(int i=0;i<nums.size();i+=2)
    {
        ans+=nums[i];
    }
    return ans;
}

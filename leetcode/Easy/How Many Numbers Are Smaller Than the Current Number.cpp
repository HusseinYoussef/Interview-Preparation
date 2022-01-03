#include <iostream>
#include <vector>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums)
{
    int arr[101];
    memset(arr, 0, sizeof(arr));
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    for(int i = 1;i<tmp.size();++i)
    {
        if(tmp[i] != tmp[i-1])
            arr[tmp[i]] = i;
    }
    for(int i =0;i<nums.size();++i)
        nums[i] = arr[nums[i]];
    return nums;
}

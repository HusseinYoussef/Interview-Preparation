#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int searchInsert(vector<int> nums, int target)
{
    auto idx = lower_bound(nums.begin(), nums.end(), target);
    return idx - nums.begin();
}
int main()
{
    vector<int> vec = {1,3,5,6};
    cout << searchInsert(vec, 0);
    return 0;
}
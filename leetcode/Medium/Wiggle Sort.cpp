#include <vector>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n - 1;i+=2)
    {
        swap(nums[i], nums[i + 1]);
    }
}
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

double findMaxAverage(vector<int>& nums, int k)
{
    int sum = 0;
    double ans = -INT64_MAX;
    for (int i = 0; i < nums.size();++i)
    {
        if(i >= k)
        {
            ans = max(ans, 1.0*sum / k);
            sum -= nums[i - k];
        }
        sum += nums[i];
    }
    ans = max(ans, 1.0*sum / k);
    return ans;
}

int main()
{
    vector<int> vec = {1,12,-5,-6,50,3};
    findMaxAverage(vec, 4);
    return 0;
}
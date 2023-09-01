#include <vector>

using namespace std;

// Given an array A of integers, find the maximum of j - i subjected to the constraint of A[i] <= A[j].
// https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

int MaximumGap(const vector<int> &nums)
{
    // O(N Log N) Time, O(N) Space Binary Search
    int n = nums.size();
    
    vector<long> rmax(n+1, INT_MIN);
    for (int i = n-1;i>=0;--i)
    {
        rmax[i] = max((long)nums[i], rmax[i+1]);
    }
    
    int ans = 0;
    for (int i = 0;i<n;++i)
    {
        int l = i, r = n, mid, j = i;
        while (r - l > 1)
        {
            mid = l + (r - l) / 2;
            if (nums[i] <= rmax[mid])
            {
                j = max(j, mid);
                l = mid;
            }
            else
                r = mid;
        }
        ans = max(ans, j - i);
    }
    return ans;

    // O(N) Time, O(N) Space Greedy
    // int n = nums.size();
    
    // vector<long> rmax(n+1, INT_MIN);
    // for (int i = n-1;i>=0;--i)
    // {
    //     rmax[i] = max((long)nums[i], rmax[i+1]);
    // }
    
    // vector<long> lmin(n+1, INT_MAX);
    // lmin[0] = nums[0];
    // for (int i = 1;i<n;++i)
    // {
    //     lmin[i] = min((long)nums[i], lmin[i-1]);
    // }
    
    // int i = 0, j = 0, ans = 0;
    // while (i < n && j < n)
    // {
    //     if (lmin[i] <= rmax[j])
    //     {
    //         ans = max(ans, j - i);
    //         ++j;
    //     }
    //     else
    //         ++i;
    // }
    // return ans;
}

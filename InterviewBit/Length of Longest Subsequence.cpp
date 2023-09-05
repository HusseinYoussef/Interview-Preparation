#include <vector>
#include <cstring>

using namespace std;

int n;
int dp1[3002];
int dp2[3002];

// 2 LDS: from left to right and from right to left
// LDS from 0 -> i
int LDSR(const vector<int> &arr, int pre)
{
    int &ret = dp1[pre];
    if (~ret)
        return ret;
        
    ret = 0;
    for (int i = pre - 1;i>=0;--i)
    {
        if (arr[i] < arr[pre])
            ret = max(ret, LDSR(arr, i) + 1);
    }
    
    return ret;
}

// LDS from i -> n
int LDSL(const vector<int> &arr, int pre)
{
    int &ret = dp2[pre];
    if (~ret)
        return ret;
        
    ret = 0;
    for (int i = pre + 1;i<n;++i)
    {
        if (arr[i] < arr[pre])
            ret = max(ret, LDSL(arr, i) + 1);
    }
    
    return ret;
}

int Solution::longestSubsequenceLength(const vector<int> &A)
{
    n = A.size();
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    for (int i = 0, j = n-1; i<n;++i, --j)
    {
        dp1[j] = max(dp1[j], LDSR(A, j) + 1);
        dp2[i] = max(dp2[i], LDSL(A, i) + 1);
    }

    int ans = 0;
    for (int i = 0;i<n;++i)
        ans = max(ans, dp1[i] + dp2[i] - 1);    
    return ans;

    // ***** Bottom Up *****

    // LIS ~ Longest Increasing Subsequence Uptill i
    int dp1[3005];
    for (int idx = 0; idx < n; ++idx)
    {
        dp1[idx] = 1;
        for (int i = idx - 1; i >= 0;--i)
        {
            if(A[i] < A[idx])
                dp1[idx] = max(dp1[idx], dp1[i] + 1);
        }
    }
    // LDS ~ Longest Decreasing Subsequence Starting with i
    int dp2[3005];
    for (int idx = n - 1; idx >= 0;--idx)
    {
        dp2[idx] = 1;
        for (int i = idx + 1; i < n;++i)
        {
            if(A[i] < A[idx])
                dp2[idx] = max(dp2[idx], dp2[i] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n;++i)
        ans = max(ans, dp1[i] + dp2[i] - 1);
    return ans;
}

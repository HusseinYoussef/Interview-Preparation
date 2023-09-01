#include <vector>

using namespace std;

// max subbarray sum and find the array (Kadane’s Algorithm)
vector<int> Solution::flip(string A)
{
    int n = A.size();

    int sum = 0, mx = INT_MIN, l = 0, r = 0, s = 0;
    for (int i = 0;i<n;++i)
    {
        sum += (A[i] == '1') ? -1 : 1;
        if (sum > mx)
        {
            mx = sum;
            l = s+1; // l, r are 1-based
            r = i+1;
        }
        
        if (sum < 0)
        {
            sum = 0;
            s = i+1;
        }
    }
    if (mx > 0)
        return {l, r};
    return {};
}

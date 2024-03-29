#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(vector<int> &A, vector<int> &B, vector<int> &C)
{
    int ans = INT_MAX;
    int i = 0, j = 0, k = 0;
    while(i < A.size() && j < B.size() && k < C.size())
    {
        int mx = max(A[i], max(B[j], C[k]));
        int mn = min(A[i], min(B[j], C[k]));

        ans = min(ans, mx - mn);
        if(mn == A[i])
            ++i;
        else if(mn == B[j])
            ++j;
        else
            ++k;
    }
    return ans;
}
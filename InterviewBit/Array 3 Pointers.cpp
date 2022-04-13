#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C)
{
    int ans = INT_MAX;
    int i = 0, j = 0, k = 0;
    while(i < A.size() && j < B.size() && k < C.size())
    {
        int mx = max(abs(A[i]-B[j]), max(abs(B[j]-C[k]), abs(C[k] - A[i])));
        ans = min(ans, mx);

        int mn = min(A[i], min(B[j], C[k]));
        if(A[i] == mn)
            ++i;
        else if(B[j] == mn)
            ++j;
        else
            ++k;
    }
    return ans;
}
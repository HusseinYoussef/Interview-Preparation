#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(string A)
{
    // Goal is to find the longest palindrome prefix
    // we can contatenate A with its reverse separated by a char, so if we get the longest prefix that is also suffix
    // that would be the longest palindrome prefix, since the suffix is the prefix reversed
    // We can compute LPS (Longest prefix suffix) just as we do for KMP.
    
    int n = A.size();
    string revstr = A;
    reverse(revstr.begin(), revstr.end());
    A = A + "#" + revstr;
    
    vector<int> lps(2 * n + 1, 0);
    for (int i = 0, j = 1; j < A.size();)
    {
        if(A[i] == A[j])
        {
            lps[j] = i + 1;
            ++i;
            ++j;
        }
        else if(i > 0)
        {
            i = lps[i - 1];
        }
        else
        {
            lps[j] = 0;
            ++j;
        }
    }
    return n - lps.back();
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k)
{
    //  Time: O(N^2), Space O(K)
    // int n = matrix.size();
    // priority_queue<int> pq;
    // for (int i = 0; i < n;++i)
    // {
    //     for (int j = 0; j < n;++j)
    //     {
    //         pq.push(matrix[i][j]);
    //         if(pq.size() > k)
    //             pq.pop();
    //     }
    // }
    // return pq.top();

    // Time O(N log range), Space O(1)
    int n = matrix.size();
    int l = matrix[0][0], r = matrix[n - 1][n - 1] + 1, mid; // [l, r)
    while(l < r)
    {
        mid = l + (r - l) / 2;
        int cnt = 0;
        int i = 0, j = n - 1;
        // O(N)
        while(j >= 0 && i < n)
        {
            if(matrix[i][j] > mid)
                --j;
            else
            {
                cnt += j + 1;
                ++i;
            }
        }
        if(cnt < k)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class Solution {
public:
    vector<int> original;
    vector<int> cur;
    int n;
    Solution(vector<int>& nums)
    {
        original = cur = nums;
        n = original.size();
    }
    
    vector<int> reset()
    {
        cur = original;
        return cur;
    }
    
    vector<int> shuffle()
    {
        // random_shuffle(cur.begin(), cur.end());
        // return cur;

        // Fisher-Yates Algorithm
        for (int i = 0; i < n; ++i)
        {
            int randIdx = rand() % (n - i) + i;
            swap(cur[i], cur[randIdx]);
        }
        return cur;
    }
};
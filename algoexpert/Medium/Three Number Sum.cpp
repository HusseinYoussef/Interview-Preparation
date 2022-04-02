
/*
    Problem Statement
    
    Write a function that takes in a non-empty array of distinct integers and an
    integer representing a target sum. The function should find all triplets in
    the array that sum up to the target sum and return a two-dimensional array of
    all these triplets. The numbers in each triplet should be ordered in ascending
    order, and the triplets themselves should be ordered in ascending order with
    respect to the numbers they hold.

    If no three numbers sum up to the target sum, the function should return an
    empty array.
*/

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum)
{
    int n = array.size();
    sort(array.begin(), array.end());

    vector<vector<int>> ans;
    for (int i = 0; i < n - 2;++i)
    {
        int l = i + 1, r = n - 1, sum = targetSum - array[i];
        while(l < r)
        {
            if(array[l] + array[r] == sum)
            {
                ans.push_back({array[i], array[l], array[r]});
                ++l, --r;
            }
            else if(array[l] + array[r] < sum)
                ++l;
            else
                --r;
        }
    }
    return ans;
}
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
  Problem Statement

  Write a function that takes in a non-empty array of distinct integers and an
  integer representing a target sum. If any two numbers in the input array sum
  up to the target sum, the function should return them in an array, in any
  order. If no two numbers sum up to the target sum, the function should return
  an empty array.

  Note that the target sum has to be obtained by summing two different integers
  in the array; you can't add a single integer to itself in order to obtain the
  target sum.
*/

// Solution 1: O(n) Time, O(n) Space
vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    int n = array.size();
	unordered_map<int, bool> mp;
	for(int i = 0;i<n;++i)
	{
			if(mp[targetSum-array[i]])
			{
				return {array[i], targetSum-array[i]};
			}
		mp[array[i]] = 1;
	}
	return {};
}

// Solution 2: O(nlogn) Time, O(1) Space
vector<int> twoNumberSum(vector<int> array, int targetSum)
{
    int n = array.size();
	sort(array.begin(), array.end());
	int l = 0, r = n-1, sum;
	while(l < r)
	{
		sum = array[l] + array[r];
		if(sum == targetSum)
			return {array[l], array[r]};
		else if(sum < targetSum)
			++l;
		else
			--r;
	}
    return {};
}

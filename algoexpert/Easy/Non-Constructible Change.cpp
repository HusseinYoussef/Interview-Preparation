
/*
    Problem Statement

    Given an array of positive integers representing the values of coins in your
    possession, write a function that returns the minimum amount of change (the
    minimum sum of money) that you cannot create. The given coins can have
    any positive integer value and aren't necessarily unique (i.e., you can have
    multiple coins of the same value).
    
    If you're given no coins, the minimum amount of change that you can't create is

    Idea:
    Key observation here is, when the integers are sorted, we can always track the highest constructible value
        by doing a cumulative sum of the sorted integers.
    At any point if the next integer is larger than max_constructible + 1, then there is no way to construct max_constructible + 1.
*/

#include <vector>
#include <algorithm>

using namespace std;

int nonConstructibleChange(vector<int> coins)
{
    sort(coins.begin(), coins.end());

    int n = coins.size();
    int change = 0;
    for (int i = 0; i < n;++i)
    {
        if(coins[i] > change+1)
            return change + 1;
        change += coins[i];
    }
    return change + 1;
}
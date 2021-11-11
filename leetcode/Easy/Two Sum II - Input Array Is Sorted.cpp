#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target)
{
    // O(N)

    // unordered_map<int, int> mp;
    // vector<int> ans;
    // for (int i = 0; i < numbers.size();++i)
    // {
    //     int val = target - numbers[i];
    //     if (mp[val])
    //     {
    //         ans.push_back(mp[val]);
    //         ans.push_back(i + 1);
    //         return ans;
    //     }
    //     mp[numbers[i]] = i + 1;
    // }
    // return ans;

    // O(N) worst
    // O(Log n) average
    vector<int> ans;
    for (int i = 0; i < numbers.size();++i)
    {
        int val = target - numbers[i];
        auto idx = lower_bound(numbers.begin() + i + 1, numbers.end(), val);
        if(idx < numbers.end() && numbers[idx - numbers.begin()] == val)
        {
            ans.push_back(i + 1);
            ans.push_back(idx - numbers.begin() + 1);
            return ans;
        }
    }
    return ans;
}

int main()
{
    vector<int> vec = {0, 0, 3, 4};
    vector<int> ans = twoSum(vec, 0);
    cout << "heloo";
    return 0;
}
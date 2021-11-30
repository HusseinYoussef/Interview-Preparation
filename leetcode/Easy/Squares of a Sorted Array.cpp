#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> sortedSquares(vector<int>& nums)
{
    int freq[10004];
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < nums.size();++i)
        ++freq[abs(nums[i])];
    vector<int> ans;
    for (int i = 0; i < 10004;++i)
    {
        int cnt = freq[i];
        while(cnt)
        {
            ans.push_back(i * i);
            --cnt;
        }
    }
    return ans;
}

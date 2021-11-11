#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums)
{
    int ans = 0;
    for(int i : nums)
        ans ^= i;
    return ans;
}

int main()
{
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(!nums.size())
        return 0;
    int k = 1;
    for (int i = 1; i < nums.size();++i)
    {
        if(nums[i] != nums[i-1])
        {
            k++;
        }
    }
    return k;
}

int main()
{
    vector<int> vec = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(vec);
    return 0;
}
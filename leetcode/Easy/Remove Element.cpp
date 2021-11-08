#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int k = 0;
    for (int i = 0; i < nums.size();++i)
    {
        if(nums[i] != val)
        {
            nums[k++] = nums[i];
        }
    }
    return k;
}
int main()
{
    vector<int> vec = {};
    cout << removeElement(vec, 2);
    return 0;
}
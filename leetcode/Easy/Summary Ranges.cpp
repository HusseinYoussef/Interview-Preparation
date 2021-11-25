#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> summaryRanges(vector<int>& nums)
{
    int a, b;
    vector<string> ans;
    if(nums.size() == 0)
        return ans;
    for (int i = 0; i < nums.size();++i)
    {
        if(i == 0)
        {
            a = b = nums[i];
        }
        else
        {
            if(nums[i] != 1 + nums[i-1])
            {
                if(a == b)
                    ans.push_back(to_string(a));
                else
                {
                    string s = to_string(a) + "-" + ">" + to_string(b);
                    ans.push_back(s);
                }
                a = b = nums[i];
            }
            else
                b = nums[i];
        }
    }
    if(a == b)
        ans.push_back(to_string(a));
    else
    {
        string s = to_string(a) + "-" + ">" + to_string(b);
        ans.push_back(s);
    }
    return ans;
}

int main()
{
    return 0;
}
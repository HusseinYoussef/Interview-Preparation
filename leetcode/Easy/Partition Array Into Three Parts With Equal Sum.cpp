#include <iostream>
#include <vector>

using namespace std;

bool canThreePartsEqualSum(vector<int>& arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size();++i)
        sum += arr[i];
    if(sum % 3 == 0)
    {
        sum = sum / 3;
        int subsum = 0;
        int cnt = 0;
        for (int i = 0; i < arr.size();++i)
        {
            // If I could find two sub-arrays with equal sum = (1/3) then the remaining array must equal to the last 1/3
            // Since I found 2/3 already
            if(cnt == 2)
                return true;
            subsum += arr[i];
            if(subsum == sum)
            {
                subsum = 0;
                ++cnt;
            }
        }
    }
    return false;
}
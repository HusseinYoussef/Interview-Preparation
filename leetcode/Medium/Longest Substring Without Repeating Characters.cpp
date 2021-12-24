#include <iostream>
#include <cstring>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.size();
    int ans = 0;
    bool arr[128];
    memset(arr, 0, sizeof(arr));
    for (int i = 0, l = 0; i < n;)
    {
        if(arr[s[i] - ' '] == 0)
        {
            arr[s[i] - ' '] = 1;
            ans = max(ans, i - l + 1);
            ++i;
        }
        else
        {
            arr[s[l] - ' '] = 0;
            ++l;
        }
    }
    return ans;
}
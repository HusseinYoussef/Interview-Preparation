#include <iostream>
#include <vector>

using namespace std;

int n;
int ans = 0;
void rec(vector<string>& arr, int cmsk, int szsum, int idx)
{
    if(idx == n)
    {
        ans = max(ans, szsum);
        return;
    }

    // leave this string
    rec(arr, cmsk, szsum, idx + 1);
    
    // Take this string ~ mark all its chars
    for (int i = 0; i < arr[idx].size();++i)
    {
        int cidx = arr[idx][i] - 'a';
        // this character appeared before
        if(cmsk & (1 << cidx))
            return;
        cmsk |= (1 << cidx);
    }
    rec(arr, cmsk, szsum + arr[idx].size(), idx + 1);
}

int maxLength(vector<string>& arr)
{
    n = arr.size();
    vector<string> strs;
    rec(arr, 0, 0, 0);
    return ans;
}
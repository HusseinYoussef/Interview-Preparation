#include <iostream>

using namespace std;

int numJewelsInStones(string jewels, string stones)
{
    bool arr[60];
    memset(arr, 0, sizeof(arr));
    for(int i =0;i<jewels.size();++i)
        arr[jewels[i]-'A'] = 1;

    int ans =0;
    for(int i =0;i<stones.size();++i)
        ans += arr[stones[i]-'A'];
    return ans;
}

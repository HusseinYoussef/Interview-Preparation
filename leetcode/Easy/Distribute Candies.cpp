#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int distributeCandies(vector<int>& candyType)
{
    bool arr[200005];
    memset(arr, 0, sizeof(arr));
    int cnt = 0;
    for (int i = 0; i < candyType.size();++i)
    {
        if(arr[candyType[i]+100000] == 0)
        {
            arr[candyType[i] + 100000] = 1;
            ++cnt;
        }
    }
    return min(cnt, (int)candyType.size() / 2);
}
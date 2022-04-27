#include <vector>

using namespace std;

int minJump(vector<int>& arr)
{
    int n = arr.size();
    if(n == 0)
        return -1;
    if(n == 1)
        return 0;
        
    int reach = arr[0], tmp = 0;
    int cnt = 0;
    for (int i = 0; i <= min(n-1, reach);++i)
    {
        tmp = max(tmp, i + arr[i]);
        if(i == min(n-1, reach))
        {
            reach = tmp;
            ++cnt;
        }
        if(i == n-1)
            return cnt;
    }
    return -1;
}
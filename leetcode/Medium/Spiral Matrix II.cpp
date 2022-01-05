#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> ans(n, vector<int>(n));
    int num = 1;
    int lr = 0, rr = n-1, lc = 0, rc = n-1;
    int c = 0;
    while(lr <= rr && lc <= rc)
    {
        if(c % 4 == 0)
        {
            for (int i = lc; i <= rc;++i)
                ans[lr][i] = num++;
            ++lr;
        }
        else if(c % 4 == 1)
        {
            for (int i = lr; i <= rr;++i)
                ans[i][rc] = num++;
            --rc;
        }
        else if(c % 4 == 2)
        {
            for (int i = rc; i >= lc;--i)
                ans[rr][i] = num++;
            --rr;
        }
        else
        {
            for (int i = rr; i >= lr;--i)
                ans[i][lc] = num++;
            ++lc;
        }
        ++c;
    }
    return ans;
}

int main()
{
    generateMatrix(3);
    return 0;
}
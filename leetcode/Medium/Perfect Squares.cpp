#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dp[10004];
int solve(vector<int> &squares, int n)
{
    if(n == 0)
        return 0;
    int &ret = dp[n];
    if(~ret)
        return ret;

    ret = 1e8;
    for(int i = 0;i<squares.size();++i)
    {
        if(squares[i] > n)
            break;
        ret = min(ret, solve(squares, n-squares[i]) + 1);
    }
    return ret;
}

int numSquares(int n)
{
    vector<int> squares;
    memset(dp, -1, sizeof(dp));
    for(int i = 1;i*i<=n;++i)
        squares.push_back(i*i);
    return solve(squares, n);

    // queue<pair<int, int>>q;
    // q.push({0,n});
    // while(!q.empty())
    // {
    //     pair<int, int> p = q.front();
    //     q.pop();
    //     for(int i = 0;i<squares.size();++i)
    //     {
    //         if(squares[i] > p.second)
    //             break;
    //         if(p.second-squares[i] == 0)
    //             return p.first+1;
    //         q.push({p.first+1, p.second-squares[i]});
    //     }
    // }
    // return 0;
}

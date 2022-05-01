#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int minFlips(vector<vector<int>>& mat)
{
    int n = mat.size(), m = mat[0].size();

    int state = 0;
    int bitIdx = 0;
    for (int i = 0; i < n;++i)
    {
        for (int j = m - 1; j >= 0;--j)
        {
            if(mat[i][j])
                state |= 1 << bitIdx;
            ++bitIdx;
        }
    }
    // BFS O(V+E) = O(V + 4*V) = O(V) = O(all states)
    // explore all possible states O(2^(m*n))
    unordered_map<int, int> dist;
    queue<int> q;
    q.push(state);
    dist[state] = 0;
    while(!q.empty())
    {
        state = q.front();
        int cst = dist[state];
        q.pop();
        if(state == 0)
            return cst;

        for (int i = 0; i < m * n;++i)
        {
            state ^= 1 << i;

            // up
            if(i - m >= 0)
                state ^= 1 << (i - m);
            // down
            if(i + m < m*n)
                state ^= 1 << (i + m);
            // right
            if(i % m > 0)
                state ^= 1 << (i - 1);
            // left
            if(i % m < m-1)
                state ^= 1 << (i + 1);
            
            if(dist.find(state) == dist.end())
            {
                if(state == 0)
                    return cst + 1;

                dist[state] = cst + 1;
                q.push(state);
            }

            // Undo
            state ^= 1 << i;

            // up
            if(i - m >= 0)
                state ^= 1 << (i - m);
            // down
            if(i + m < m*n)
                state ^= 1 << (i + m);
            // right
            if(i % m > 0)
                state ^= 1 << (i - 1);
            // left
            if(i % m < m-1)
                state ^= 1 << (i + 1);
        }
    }
    return -1;
}
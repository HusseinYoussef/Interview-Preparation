#include <queue>

using namespace std;

int knight(int A, int B, int C, int D, int E, int F)
{
    // start position may be the end position
    if(C == E && D == F)
        return 0;
        
    vector<vector<int>> dist(A + 1, vector<int>(B + 1, -1));
    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

    queue<pair<int, int>> q;
    q.push({C, D});
    dist[C][D] = 0;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int cst = dist[x][y];
        q.pop();


        for (int i = 0; i < 8;++i)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= A && ny >= 1 && ny <= B && dist[nx][ny] == -1)
            {
                if(nx == E && ny == F)
                    return cst + 1;

                dist[nx][ny] = cst + 1;
                q.push({nx, ny});
            }
        }
    }
    return -1;
}
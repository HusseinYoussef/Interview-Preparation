#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat)
{
    int n = mat.size(), m = mat[0].size();
    vector<vector<int>> diagonals(n + m);
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            diagonals[i + j].push_back(mat[i][j]);
        }
    }

    for (int i = 0; i < diagonals.size();i+=2)
        reverse(diagonals[i].begin(), diagonals[i].end());

    vector<int> ans;
    for (int i = 0; i < diagonals.size();++i)
    {
        for (int j = 0; j < diagonals[i].size();++j)
            ans.push_back(diagonals[i][j]);
    }
    return ans;
}
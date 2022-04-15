#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root)
{
    // map of cols, each col has a map of row. each row is a multiset to sort its values
    map<int, map<int, multiset<int>>> cols;

    // {node, [row, col]}
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0,0}});
    while(!q.empty())
    {
        TreeNode *node = q.front().first;
        int row = q.front().second.first;
        int col = q.front().second.second;
        cols[col][row].insert(node->val);
        
        q.pop();
        if(node->left)
            q.push({node->left, {row + 1, col - 1}});
        if(node->right)
            q.push({node->right, {row + 1, col + 1}});
    }

    // build answer
    vector<vector<int>> ans;
    for(auto &col : cols)
    {
        vector<int> tmp;
        for(auto &row : col.second)
        {
            if(row.second.size())
            {
                for(auto &val : row.second)
                    tmp.push_back(val);
            }
        }
        if (tmp.size())
            ans.push_back(tmp);
    }
    return ans;
}
#include <vector>
#include <queue>
#include <map>

using namespace std;

class TreeNode
{
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = nullptr;
    }
};

vector<vector<int>> verticalOrder(TreeNode *root)
{
    if(root == nullptr)
        return {};

    map<int, vector<int>> cols;
    queue<pair<int, TreeNode*>> q;
    q.push({0, root});

    while(!q.empty())
    {
        pair<int, TreeNode*> p = q.front();
        q.pop();
        int col = p.first;
        TreeNode *node = p.second;
        cols[col].push_back(node->val);
        if(node->left)
        {
            q.push({col - 1, node->left});
        }
        if(node->right)
        {
            q.push({col + 1, node->right});
        }
    }
    vector<vector<int>> ans;
    for(auto p : cols)
        ans.push_back(p.second);
    return ans;
}
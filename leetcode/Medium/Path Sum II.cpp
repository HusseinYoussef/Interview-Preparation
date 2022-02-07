#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(vector<vector<int>> &ans, TreeNode* node, vector<int> &path, int sum)
{
    if(node == nullptr)
        return;
    path.push_back(node->val);
    sum -= node->val;
    if(node->left == nullptr && node->right == nullptr)
    {
        if(sum == 0)
            ans.push_back(path);
        path.pop_back();
        return;
    }
    dfs(ans, node->left, path, sum);
    dfs(ans, node->right, path, sum);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum)
{
    vector<vector<int>> ans;
    vector<int> path = {};
    dfs(ans, root, path, targetSum);
    return ans;
}

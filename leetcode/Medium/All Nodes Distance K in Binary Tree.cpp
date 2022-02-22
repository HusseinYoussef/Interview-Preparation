#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void dfs(unordered_map<int, TreeNode *> &mp, TreeNode* node, TreeNode* par)
{
    if(node == nullptr)
        return;

    mp[node->val] = par;
    dfs(mp, node->left, node);
    dfs(mp, node->right, node);
}

void solve(unordered_map<int, TreeNode *> &mp, vector<int> &ans, TreeNode* node, TreeNode* par, int dis)
{
    if(node == nullptr)
        return;
    if(dis == 0)
    {
        ans.push_back(node->val);
        return;
    }

    if(par != node->left)
        solve(mp, ans, node->left, node, dis - 1);
    if(par != mp[node->val])
        solve(mp, ans, mp[node->val], node, dis - 1);
    if(par != node->right)
        solve(mp, ans, node->right, node, dis - 1);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
{
    vector<int> ans;
    unordered_map<int, TreeNode *> mp;
    dfs(mp, root, nullptr);
    solve(mp, ans, target, nullptr, k);
    return ans;
}
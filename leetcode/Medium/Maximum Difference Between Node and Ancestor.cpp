#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans = -1;
void dfs(TreeNode* node, int mx = -1, int mn = 100006)
{
    if(node == nullptr)
    {
        ans = max(ans, mx - mn);
        return;
    }    

    mx = max(mx, node->val);
    mn = min(mn, node->val);            
    dfs(node->left, mx, mn);
    dfs(node->right, mx, mn);
}

int maxAncestorDiff(TreeNode* root)
{
    dfs(root, ans);
    return ans;
}

#include <climits>

using namespace std;

int ans = INT_MIN;
int dfs(TreeNode* node)
{
    if (!node)
        return -4e7;

    int l = dfs(node->left);
    int r = dfs(node->right);

    ans = max(ans, max(l, r));
    ans = max(ans, max(l, r) + node->val);
    ans = max(ans, max(l + r + node->val, node->val));

    return max(max(l, r) + node->val, node->val);
}

int maxPathSum(TreeNode* root)
{
    ans = INT_MIN;
    dfs(root);
    return ans;
}

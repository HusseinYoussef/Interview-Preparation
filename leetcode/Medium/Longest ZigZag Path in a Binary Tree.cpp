#include <vector>

using namespace std;

// 0 -> left, 1 -> right
int ans = 0;
void dfs(TreeNode* node, int dir, int depth)
{
    if (!node)
        return;

    ans = max(ans, depth);
    dfs(node->left, 0, (dir != 0) ? depth + 1 : 1);
    dfs(node->right, 1, (dir != 1) ? depth + 1 : 1);
}

int longestZigZag(TreeNode* root)
{
    ans = 0;
    dfs(root, -1, 0);
    return ans; 
}

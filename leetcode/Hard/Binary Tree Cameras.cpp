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

/*
Here is our greedy solution:

Set cameras on all leaves' parents, then remove all covered nodes.
Repeat step 1 until all nodes are covered.
*/

// Return 0 if it's a leaf.
// Return 1 if it's a parent of a leaf, with a camera on this node.
// Return 2 if it's coverd, without a camera on this node.
int ans = 0;
int dfs(TreeNode* node)
{
    if(node == nullptr)
        return 2;

    int left = dfs(node->left), right = dfs(node->right);
    if(left == 0 || right == 0)
    {
        ++ans;
        return 1;
    }
    return (left == 1 || right == 1) ? 2 : 0;
}

int minCameraCover(TreeNode* root)
{
    return (dfs(root) == 0) + ans;
}
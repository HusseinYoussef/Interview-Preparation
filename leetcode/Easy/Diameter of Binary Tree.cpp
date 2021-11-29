#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// O(N)
// max value of (height of left subtree + height of right subtree + 1) at each node
int mx = 0;
int dfs(TreeNode* node)
{
    if(!node)
        return 0;
    if(node->left == nullptr && node->right == nullptr)
    {
        return 1;
    }
    int l = dfs(node->left);
    int r = dfs(node->right);
    mx = max(mx, l + r + 1);
    return max(l, r) + 1;
}

int diameterOfBinaryTree(TreeNode* root)
{
    dfs(root);
    return max(mx - 1, 0);
}

int main()
{
    TreeNode *node = new TreeNode(1);
    node->left = new TreeNode(2);
    diameterOfBinaryTree(node);
    return 0;
}
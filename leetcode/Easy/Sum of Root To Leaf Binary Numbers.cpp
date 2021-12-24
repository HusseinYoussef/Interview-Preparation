#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sum = 0;
void solve(TreeNode* node, int val)
{
    if(node == nullptr)
        return;
    if(node->left == nullptr && node->right == nullptr)
    {
        val = (val << 1) | node->val;
        sum += val;
        return;
    }
    val = (val << 1) | node->val;
    solve(node->left, val);
    solve(node->right, val);
}

int sumRootToLeaf(TreeNode* root)
{
    solve(root, 0);
    return sum;
}
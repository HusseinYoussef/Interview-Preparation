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

bool solve(TreeNode* root, int val)
{
    if(root == nullptr)
        return 1;
    if(root->val != val)
        return 0;
    return solve(root->left, val) && solve(root->right, val);
}

bool isUnivalTree(TreeNode* root)
{
    return solve(root, root ? root->val : 0);
}
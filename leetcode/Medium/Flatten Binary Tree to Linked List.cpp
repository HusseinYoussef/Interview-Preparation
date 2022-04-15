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

TreeNode *pre = nullptr;
void solve(TreeNode* node)
{
    if(node == nullptr)
        return;

    // tmp r since it may get changed
    TreeNode *r = node->right;
    if(pre)
        pre->right = node;
    pre = node;
    solve(node->left);
    solve(r);
    node->left = nullptr;
}

void flatten(TreeNode* root)
{
    solve(root);
}
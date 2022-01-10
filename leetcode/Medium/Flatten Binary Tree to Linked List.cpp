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

TreeNode* solve(TreeNode* node)
{
    if(node == nullptr)
        return nullptr;

    TreeNode *l = solve(node->left);
    TreeNode *r = solve(node->right);
    node->left = nullptr;

    node->right = (l) ? l : r;
    while(l && l->right)
        l = l->right;
    if(l)
        l->right = r;
    return node;
}

void flatten(TreeNode* root)
{
    solve(root);
}
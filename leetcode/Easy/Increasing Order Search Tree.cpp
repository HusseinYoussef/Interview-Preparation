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

TreeNode* tree, *cur;
void inOrder(TreeNode* node)
{
    if(node == nullptr)
        return;
    inOrder(node->left);
    if(tree == nullptr)
    {
        tree = cur = node;
    }
    else
    {
        cur = cur->right = node;
    }
    node->left = nullptr;
    inOrder(node->right);
}

TreeNode* increasingBST(TreeNode* root) {
    inOrder(root);
    return tree;
}

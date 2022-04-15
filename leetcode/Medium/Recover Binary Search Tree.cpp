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

TreeNode* first = nullptr;
TreeNode* second = nullptr;
TreeNode* pre = nullptr;
void inorder(TreeNode* node)
{
    if(node == nullptr)
        return;
    
    inorder(node->left);
    
    if(first == nullptr && pre && node->val < pre->val)
        first = pre;
    if(first != nullptr && pre && node->val < pre->val)
        second = node;
    pre = node;
    inorder(node->right);
}

void recoverTree(TreeNode* root) {
    inorder(root);
    swap(first->val, second->val);
}
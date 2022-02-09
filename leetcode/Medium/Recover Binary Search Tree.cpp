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
TreeNode* pre = new TreeNode(INT_MIN);
void inOrder(TreeNode* root)
{
    if(root == nullptr)
        return;

    inOrder(root->left);

    if(first == nullptr && pre->val > root->val)
        first = pre;
    if(first != nullptr && root->val < pre->val)
        second = root;
    pre = root;
    inOrder(root->right);
}

void recoverTree(TreeNode* root)
{
    inOrder(root);
    swap(first->val, second->val);
}

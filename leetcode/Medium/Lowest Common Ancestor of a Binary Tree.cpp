#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root == nullptr)
        return nullptr;
    if(root->val == p->val || root->val == q->val)
        return root;

    TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);

    // if both not null, then one node in the left subtree and the other in the right subtree
    if(leftLCA != nullptr && rightLCA != nullptr)
        return root;
    
    // else both on the same subtree
    if(leftLCA != nullptr)
        return leftLCA;
    return rightLCA;
}
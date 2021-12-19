#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool n1 = 0, n2 = 0;
void dfs(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root == nullptr)
        return;
    if(root->val == p->val)
        n1 = 1;
    if(root->val == q->val)
        n2 = 1;

    dfs(root->left, p, q);
    dfs(root->right, p, q);
}

TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root == nullptr)
        return nullptr;
    if(root->val == p->val || root->val == q->val)
        return root;

    TreeNode *leftLCA = solve(root->left, p, q);
    TreeNode *rightLCA = solve(root->right, p, q);

    // if both not null, then one node in the left subtree and the other in the right subtree
    if(leftLCA != nullptr && rightLCA != nullptr)
        return root;
    
    // else both on the same subtree
    if(leftLCA != nullptr)
        return leftLCA;
    return rightLCA;
}

TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
{
    dfs(root, A, B);
    if(n1 && n2)
        return solve(root, A, B);
    return nullptr;
}
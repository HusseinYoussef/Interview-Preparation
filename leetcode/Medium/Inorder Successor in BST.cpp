#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *ans = nullptr;
// since it is a BST we want the smallest value bigger than p, so we move accordingly
void solve(TreeNode * root, TreeNode * p)
{
    if(root == nullptr)
        return;
    
    if(root->val > p->val)
    {
        if(ans == nullptr || ans->val > root->val)
            ans = root;
        solve(root->left, p);
    }
    else
        solve(root->right, p);
}

TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p)
{
    solve(root, p);
    return ans;
}
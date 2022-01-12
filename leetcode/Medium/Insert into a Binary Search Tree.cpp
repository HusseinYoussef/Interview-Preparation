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

TreeNode* insertIntoBST(TreeNode* root, int val)
{
    if(root == nullptr)
        return new TreeNode(val);

    TreeNode *pre = nullptr, *tmp = root;
    while(tmp)
    {
        pre = tmp;
        if(val > tmp->val)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    if(val > pre->val)
        pre->right = new TreeNode(val);
    else
        pre->left = new TreeNode(val);
    return root;
}
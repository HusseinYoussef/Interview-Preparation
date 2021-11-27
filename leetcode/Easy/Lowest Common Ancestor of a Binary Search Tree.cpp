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
    // if(p->val > root->val && q->val > root->val)
    //     return lowestCommonAncestor(root->right, p, q);
    // else if(p->val < root->val && q->val < root->val)
    //     return lowestCommonAncestor(root->left, p, q);
    // return root;

    TreeNode *tmp = root;
    while(tmp)
    {
        if(p->val > tmp->val && q->val > tmp->val)
            tmp = tmp->right;
        else if(p->val < tmp->val && q->val < tmp->val)
            tmp = tmp->left;
        else
            return tmp;
    }
    return tmp;
}
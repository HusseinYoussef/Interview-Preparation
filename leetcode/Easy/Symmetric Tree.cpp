#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool rec(TreeNode* p, TreeNode* q)
{
    if(!p && !q)
        return true;
    if((p && !q) || (!p && q) || (p->val != q->val))
        return false;
    return rec(p->left, q->right) & rec(p->right, q->left);
}


bool isSymmetric(TreeNode* root)
{
    return rec(root->left, root->right);
}

int main()
{
    return 0;
}
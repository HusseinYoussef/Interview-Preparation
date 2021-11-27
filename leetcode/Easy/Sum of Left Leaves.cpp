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

int sum = 0;
void rec(TreeNode* node, bool branch=1)
{
    if(!node)
        return;
    if(!node->left && !node->right && branch == 0)
    {
        sum += node->val;
        return;
    }
    rec(node->left, 0);
    rec(node->right, 1);
}

int sumOfLeftLeaves(TreeNode* root)
{
    rec(root);
    return sum;
}
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool rec(TreeNode *node, TreeNode *sub)
{
    if(!node && !sub)
        return true;
    if(!sub || !node || node->val != sub->val)
        return false;

    return rec(node->left, sub->left) && rec(node->right, sub->right);
}

bool isSubtree(TreeNode *root, TreeNode *subRoot)
{
    if(!root)
        return false;
    if(rec(root, subRoot))
        return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    // root->left->right->left = new TreeNode(0);

    TreeNode *sub = new TreeNode(4);
    sub->left = new TreeNode(1);
    sub ->right= new TreeNode(2);
    cout << isSubtree(root, sub);
    return 0;
} 
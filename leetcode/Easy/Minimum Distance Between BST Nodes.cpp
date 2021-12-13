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

int mn = 100005;
int pre = -1;
void dfs(TreeNode* node)
{
    if(node == nullptr)
        return;
    dfs(node->left);
    if(pre != -1)
        mn = min(mn, abs(pre - node->val));
    pre = node->val;
    dfs(node->right);
}
int minDiffInBST(TreeNode* root)
{
    dfs(root);
    return mn;
}

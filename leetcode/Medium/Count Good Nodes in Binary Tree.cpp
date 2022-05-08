#include <iostream>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans = 0;
void dfs(TreeNode* node, int mn=INT_MIN)
{
    if(node == nullptr)
        return;
    
    if(node->val >= mn)
        ++ans;
    mn = max(mn, node->val);
    dfs(node->left, mn);
    dfs(node->right, mn);
}

int goodNodes(TreeNode* root)
{
    dfs(root);
    return ans;
}
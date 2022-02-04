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

int ans = 0;
void dfs(TreeNode* node, int num=0)
{
    if(node == nullptr)
        return;
    num = num * 10 + node->val;
    if(node->left == nullptr && node->right == nullptr)
    {
        ans += num;
        return;
    }
    dfs(node->left, num);
    dfs(node->right, num);
}

int sumNumbers(TreeNode* root)
{
    dfs(root);
    return ans;
}

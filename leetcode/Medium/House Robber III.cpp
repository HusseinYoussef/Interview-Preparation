#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

unordered_map<TreeNode *, int> dp;
int solve(TreeNode* node)
{
    if(node == nullptr)
        return 0;

    if(dp.find(node) != dp.end())
        return dp[node];

    int l = solve(node->left);
    int r = solve(node->right);
    int a = solve(node->left ? node->left->left : nullptr);
    int b = solve(node->left ? node->left->right : nullptr);
    int c = solve(node->right ? node->right->left : nullptr);
    int d = solve(node->right ? node->right->right : nullptr);
    return dp[node] = max(l + r, a + b + c + d + node->val);
}

int rob(TreeNode* root)
{
    return solve(root);
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(100);
    root->right->right = new TreeNode(100);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(100);
    root->left->right = new TreeNode(100);

    cout << rob(root);
    return 0;
}
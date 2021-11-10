#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool bal = 1;

int dfs(TreeNode* node)
{
    if(!node || !bal)
        return 0;
    if((node->left == nullptr && node->right == nullptr))
        return 1;

    int l = dfs(node->left);
    int r = dfs(node->right);
    bal &= abs(l - r) <= 1;
    return max(l, r) + 1;
}

bool isBalanced(TreeNode* root)
{
    dfs(root);
    return bal;
}

int main()
{
    return 0;
}
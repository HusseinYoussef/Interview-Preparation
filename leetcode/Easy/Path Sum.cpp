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

bool rec(TreeNode* node, int targetSum, int sum=0)
{
    if(!node)
        return false;
    if(node->left == nullptr && node->right == nullptr)
        return sum + node->val == targetSum;
    return rec(node->left, targetSum, sum + node->val) | rec(node->right, targetSum, sum + node->val);
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    return rec(root, targetSum);
}

int main()
{
    return 0;
}
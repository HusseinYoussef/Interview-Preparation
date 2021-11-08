#include <iostream>
#include <vector>
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

int rec(TreeNode* node, int depth=0)
{
    if(!node)
        return depth;
    return max(rec(node->left, depth + 1), rec(node->right, depth + 1));
}

int maxDepth(TreeNode* root)
{
    return rec(root);
}

int main()
{
    return 0;
}
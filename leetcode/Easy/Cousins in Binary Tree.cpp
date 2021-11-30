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

int depth1 = -1;
int depth2 = -1;
int parent1 = -1;
int parent2 = -1;

void dfs(TreeNode* node, int depth, int parent, int x, int y)
{
    if(!node)
        return;

    if(node->val == x)
    {
        depth1 = depth;
        parent1 = parent;
    }
    else if(node->val == y)
    {
        depth2 = depth;
        parent2 = parent;
    }

    dfs(node->left, depth + 1, node->val, x, y);
    dfs(node->right, depth + 1, node->val, x, y);
}

bool isCousins(TreeNode* root, int x, int y)
{
    dfs(root, 0, root->val, x, y);
    return (depth1 == depth2) && (parent1 != parent2);
}
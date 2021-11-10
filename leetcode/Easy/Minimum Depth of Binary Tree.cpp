#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int rec(TreeNode* node)
{
    if(!node)
        return 1e6;
    if(node->left == nullptr && node->right == nullptr)
        return 1;

    return min(rec(node->left) + 1, rec(node->right) + 1);
}

int minDepth(TreeNode* root)
{
    return root ? rec(root) : 0;
}

int main()
{

    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void postorder(TreeNode* node, vector<int> &leaves)
{
    if(!node)
        return;
    if(node->left == nullptr && node->right == nullptr)
    {
        leaves.push_back(node->val);
        return;
    }
    postorder(node->left, leaves);
    postorder(node->right, leaves);
}

bool leafSimilar(TreeNode* root1, TreeNode* root2)
{
    vector<int> v1, v2;
    postorder(root1, v1);
    postorder(root2, v2);
    return v1 == v2;
}
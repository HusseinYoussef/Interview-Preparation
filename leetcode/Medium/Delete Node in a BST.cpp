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

TreeNode* deleteNode(TreeNode* root, int key)
{
    if(root == nullptr)
        return nullptr;
    
    if(key < root->val)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->val)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // node to be deleted
        // Case 1 
        if(root->left == nullptr && root->right == nullptr)
            return nullptr;
        // Case 2: one Child subtree
        if(root->left == nullptr)
            return root->right;
        if(root->right == nullptr)
            return root->left;
        // Case 3 Two child subtrees: Get replace with the smallest element in right subtree or largest element in left subtree
        TreeNode *tmp = root->right;
        while(tmp->left)
            tmp = tmp->left;
        root->val = tmp->val;
        // remove the tmp node
        root->right = deleteNode(root->right, tmp->val);
    }
    return root;
}
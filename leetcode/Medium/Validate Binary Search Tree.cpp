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

bool ans = 1;
pair<int,int> isBST(TreeNode* node)
{
    if(node == nullptr || ans == 0)
        return {-1,-1};
    if(node->left == nullptr && node->right == nullptr)
        return {node->val, node->val};

    pair<int,int> l = isBST(node->left);
    pair<int,int> r = isBST(node->right);

    int mn = node->val;
    int mx = node->val;
    if(node->left)
    {
        // root is larger than largest value in left subtree
        ans &= node->val > l.second;
        mn = min(mn, l.first);
    }
    if(node->right)
    {
        // root is smaller than smallest value in right subtree
        ans &= node->val < r.first;
        mx = max(mx, r.second);
    }
    return {mn, mx};
}

bool rec(TreeNode* node, long mn=LONG_MIN, long mx=LONG_MAX)
{
    if(node == nullptr)
        return true;
    
    bool l = rec(node->left, mn, node->val);
    bool r = rec(node->right, node->val, mx);
    
    return l && r && node->val > mn && node->val < mx;
}

bool isValidBST(TreeNode* root)
{
    isBST(root);
    return ans;
}
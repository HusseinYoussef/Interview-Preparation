#include <iostream>
#include <vector>
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

int rootIdx;
unordered_map<int, int> mp;
TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int l, int r)
{
    if(r < l)
        return nullptr;
    int root = postorder[rootIdx--];
    TreeNode *node = new TreeNode(root);

    node->right = solve(inorder, postorder, mp[root] + 1, r);
    node->left = solve(inorder, postorder, l, mp[root] - 1);
    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    for (int i = 0; i < inorder.size();++i)
        mp[inorder[i]] = i;
    rootIdx = postorder.size() - 1;
    return solve(inorder, postorder, 0, inorder.size() - 1);
}
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

vector<string> ans;
void rec(TreeNode* node, string path)
{
    if(!node)
        return;
    if(path.size())
        path += "->" + to_string(node->val);
    else
        path = to_string(node->val);

    if(!node->left && !node->right)
        ans.push_back(path);
    else
    {
        rec(node->left, path);
        rec(node->right, path);
    }
}

vector<string> binaryTreePaths(TreeNode* root)
{
    rec(root, "");
    return ans;
}
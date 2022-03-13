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

int ans = 0;
unordered_map<int, int> mp;
void dfs(TreeNode* node, int targetSum, int prefix)
{
    if(node == nullptr)
        return;

    prefix += node->val;
    if(prefix == targetSum)
        ++ans;
    if(mp[prefix-targetSum])
        ans += mp[prefix-targetSum];
    ++mp[prefix];
    dfs(node->left, targetSum, prefix);
    dfs(node->right, targetSum, prefix);
    // not to make this prefix affect other branches 
    --mp[prefix];
}

int pathSum(TreeNode* root, int targetSum)
{
    dfs(root, targetSum, 0);
    return ans;
}
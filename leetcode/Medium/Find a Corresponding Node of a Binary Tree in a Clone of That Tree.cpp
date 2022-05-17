
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* ans = nullptr;
void dfs(TreeNode* node, TreeNode* target)
{
    if(node == nullptr || ans != nullptr)
        return;
    
    if(node->val == target->val)
    {
        ans = node;
        return;
    }
    
    dfs(node->left, target);
    dfs(node->right, target);
}

TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
{
    dfs(cloned, target);
    return ans;
}
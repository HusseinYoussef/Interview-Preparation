
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

void dfs(TreeNode* node, int d, int val, int depth)
{
    if(node == nullptr)
        return;
    if(d == depth-1)
    {
        TreeNode *l = new TreeNode(val);
        TreeNode *r = new TreeNode(val);
        l->left = node->left;
        r->right = node->right;
        node->left = l;
        node->right = r;
        return;
    }
    dfs(node->left, d + 1, val, depth);
    dfs(node->right, d + 1, val, depth);
}

TreeNode* addOneRow(TreeNode* root, int val, int depth)
{
    if(depth == 1)
    {
        TreeNode *node = new TreeNode(val);
        node->left = root;
        return node;
    }
    dfs(root, 1, val, depth);
    return root;
}
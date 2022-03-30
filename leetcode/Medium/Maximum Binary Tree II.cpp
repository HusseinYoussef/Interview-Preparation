
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* insertIntoMaxTree(TreeNode* root, int val)
{
    TreeNode *tmp = root, *pre = nullptr;
    while(tmp)
    {
        if(tmp->val < val)
            break;
        pre = tmp;
        tmp = tmp->right;
    }
    // since it is appended, node won't have right branch, and it will be on the right branch of some node
    TreeNode *node = new TreeNode(val);
    node->left = tmp;
    if(pre == nullptr)
        root = node;
    else
        pre->right = node;
    return root;
}
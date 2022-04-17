using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* pre = nullptr, *head = nullptr;
void inorder(TreeNode* node)
{
    if(node == nullptr)
        return;
    
    inorder(node->left);    
    if(pre)
    {
        pre->left = nullptr;
        pre->right = node;
    }
    else
        head = node;
    pre = node;
    inorder(node->right);
}

TreeNode* increasingBST(TreeNode* root)
{
    inorder(root);
    if(pre)
        pre->left = pre->right = nullptr;
    return head;
}
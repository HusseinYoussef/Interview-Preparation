
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int cur = 1, ans = 0;
void inorder(TreeNode* node, int k)
{
    if(node == nullptr)
        return;

    inorder(node->left, k);
    if(cur == k)
        ans = node->val;
    ++cur;
    inorder(node->right, k);
}

int kthSmallest(TreeNode* root, int k)
{
    inorder(root, k);
    return ans;
}
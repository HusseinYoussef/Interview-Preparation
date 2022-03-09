#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isCompleteTree(TreeNode* root)
{
    queue<TreeNode *> q;
    root->val = 0;
    q.push(root);
    int preLvl = 0, i = -1;
    while(!q.empty())
    {
        if(preLvl && preLvl != (1 << i))
            return false;
        ++i;
        preLvl = q.size();
        int pre = -1;
        for (int i = 0; i < preLvl;++i)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
            {
                node->left->val = node->val * 2;
                q.push(node->left);
            }
            if(node->right)
            {
                node->right->val = node->val * 2 + 1;
                q.push(node->right);
            }
            if(node->val - pre != 1)
                return false;
            pre = node->val;
        }
    }
    return true;
}
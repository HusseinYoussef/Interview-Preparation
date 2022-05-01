#include <queue>
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

bool isEvenOddTree(TreeNode* root)
{
    queue<TreeNode *> q;
    q.push(root);
    bool odd = 0;
    while(!q.empty())
    {
        int lvl = q.size();
        int pre;
        if(odd)
            pre = INT_MAX;
        else
            pre = INT_MIN;

        for (int i = 0; i < lvl;++i)
        {
            TreeNode *node = q.front();
            q.pop();

            if(odd && (node->val >= pre || node->val & 1))
                return false;
            else if(!odd && (node->val <= pre || !(node->val & 1)))
                return false;

            pre = node->val;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        odd = !odd;
    }
    return true;
}
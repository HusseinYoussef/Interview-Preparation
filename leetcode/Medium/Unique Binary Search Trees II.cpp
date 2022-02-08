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

vector<TreeNode*> rec(int l, int r)
{
    vector<TreeNode*> ans;
    if(r < l)
    {
        ans.push_back(nullptr);
        return ans;
    }

    for(int i = l;i<=r;++i)
    {
        vector<TreeNode*> lefts = rec(l, i-1);
        vector<TreeNode*> rights = rec(i+1, r);

        for(TreeNode* left : lefts)
        {
            for(TreeNode* right : rights)
            {
                TreeNode* root = new TreeNode(i);
                root->left = left;
                root->right = right;
                ans.push_back(root);
            }
        }
    }
    return ans;
}

vector<TreeNode*> generateTrees(int n)
{
    return rec(1,n);
}

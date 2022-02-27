#include <queue>
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

vector<int> rightSideView(TreeNode* root)
{
    if(root == nullptr)
        return {};

    queue<TreeNode*> q;
    q.push(root);
    vector<int> ans;
    while(!q.empty())
    {
        int lvl = q.size();
        ans.push_back(q.back()->val);
        for(int i = 0;i<lvl;++i)
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
    return ans;
}

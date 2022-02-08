#include <vector>
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
 
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if(root)
        q.push(root);
    while(!q.empty())
    {
        int lvl = q.size();
        vector<int> nodes;
        for(int i = 0;i<lvl;++i)
        {
            TreeNode* node = q.front();
            q.pop();
            nodes.push_back(node->val);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        if(nodes.size())
            ans.push_back(nodes);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

#include <vector>
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

vector<int> largestValues(TreeNode* root)
{
    if(root == nullptr)
        return {};
        
    vector<int> ans;
    queue<TreeNode *> q;
    q.push(root);
    while(!q.empty())
    {
        int lvl = q.size();
        int mx = INT_MIN;
        for (int i = 0; i < lvl;++i)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            mx = max(mx, node->val);
        }
        ans.push_back(mx);
    }
    return ans;
}
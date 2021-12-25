#include <iostream>
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

vector<vector<int>> levelOrder(TreeNode* root)
{
    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty())
    {
        int p = q.size();
        vector<int> lvl;
        for (int i = 0; i < p;++i)
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr)
                continue;
            lvl.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        if(!lvl.empty())
            ans.push_back(lvl);
    }
    return ans;
}
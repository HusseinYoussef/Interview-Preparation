#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    q.push(root);
    bool f = 0;
    while(!q.empty())
    {
        int p = q.size();
        vector<int> nodes;
        for (int i = 0; i < p;++i)
        {
            TreeNode *node = q.front();
            q.pop();
            if(node == nullptr)
                continue;
            nodes.push_back(node->val);
            q.push(node->left);
            q.push(node->right);
        }
        if(f)
            reverse(nodes.begin(), nodes.end());
        if(nodes.size())
            ans.push_back(nodes);
        f = !f;
    }
    return ans;
}
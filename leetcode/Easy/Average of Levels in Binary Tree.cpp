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

vector<double> averageOfLevels(TreeNode* root)
{
    queue<TreeNode *> q;
    q.push(root);
    int p = 1, c;
    vector<double> ans;
    while(!q.empty())
    {
        long long sum = 0;
        for (int i = 0; i < p;++i)
        {
            TreeNode *node = q.front();
            q.pop();
            sum += node->val;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        ans.push_back(1.0*sum / p);
        p = q.size();
    }
    return ans;
}
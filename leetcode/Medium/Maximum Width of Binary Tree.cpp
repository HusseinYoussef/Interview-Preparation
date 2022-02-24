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

int widthOfBinaryTree(TreeNode* root)
{
    if(root == nullptr)
        return 0;

    queue<pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});
    unsigned long long ans = 0;
    while(!q.empty())
    {
        int lvl = q.size();
        ans = max(ans, q.back().second - q.front().second + 1);
        for (int i = 0; i < lvl;++i)
        {
            TreeNode* node = q.front().first;
            unsigned long long idx = q.front().second;
            q.pop();
            if(node->left)
                q.push({node->left, idx * 2});
            if(node->right)
                q.push({node->right, idx * 2 + 1});
        }
    }
    return (int)ans;
}
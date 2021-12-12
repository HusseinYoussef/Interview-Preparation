#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int freq[200005];
int mx_count = 0;
void dfs(TreeNode* node)
{
    if(node == nullptr)
        return;
    freq[node->val + 100000]++;
    mx_count = max(mx_count, freq[node->val + 100000]);
    dfs(node->left);
    dfs(node->right);
}

vector<int> findMode(TreeNode* root)
{
    memset(freq, 0, sizeof(freq));
    vector<int>ans;
    dfs(root);
    for(int i =0;i<=200000;++i)
        if(freq[i] == mx_count)
            ans.push_back(i-100000);
    return ans;
}

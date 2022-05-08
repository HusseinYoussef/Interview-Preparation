#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int mxfreq = -1;
unordered_map<int, vector<int>> mp;
unordered_map<int, int> freq;
int dfs(TreeNode* node)
{
    if(node == nullptr)
        return 0;

    int sum = dfs(node->left) + dfs(node->right) + node->val;
    ++freq[sum];
    if(freq[sum] > mxfreq)
        mp[freq[sum]].push_back(sum);
    mxfreq = max(mxfreq, freq[sum]);
    return sum;
}

vector<int> findFrequentTreeSum(TreeNode* root)
{
    dfs(root);
    return mp[mxfreq];
}
#include <iostream>
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

string post(TreeNode* node, unordered_map<string, int> &mp, vector<TreeNode*> &ans)
{
    if(node == nullptr)
        return "";

    string l = post(node->left, mp, ans);
    string r = post(node->right, mp, ans);

    string encoding = l + ((l.empty()) ? "" : "<") + to_string(node->val) + ((r.empty()) ? "" : ">") + r;
    if(mp[encoding] == 1)
        ans.push_back(node);
    mp[encoding]++;
    return encoding;
}

vector<TreeNode*> findDuplicateSubtrees(TreeNode* root)
{
    vector<TreeNode *> ans;
    unordered_map<string, int> mp;
    post(root, mp, ans);
    return ans;
}
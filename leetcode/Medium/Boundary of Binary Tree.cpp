#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

vector<int> vec;
unordered_map<TreeNode *, bool> mp;
void dfs(TreeNode* node)
{
    if(node == nullptr)
        return;
    if(node->left == nullptr && node->right == nullptr && mp[node] != 1)
    {
        vec.push_back(node->val);
        mp[node] = 1;
    }
    dfs(node->left);
    dfs(node->right);
}

vector<int> boundaryOfBinaryTree(TreeNode * root)
{
    vector<int> ans;
    if(root == nullptr)
        return {};
    if(root->left == nullptr && root->right == nullptr)
        return {root->val};
    
    vec.push_back(root->val);
    mp[root] = 1;
    TreeNode *tmp = root->left;
    while(tmp)
    {
        if(mp[tmp] != 1)
        {
            vec.push_back(tmp->val);
            mp[tmp] = 1;
        }
        if(tmp->left)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    for (int i = 0; i < vec.size();++i)
        ans.push_back(vec[i]);
    vec.clear();
    dfs(root);
    for (int i = 0; i < vec.size();++i)
        ans.push_back(vec[i]);
    vec.clear();
    tmp = root->right;
    while(tmp)
    {
        if(mp[tmp] != 1)
        {
            vec.push_back(tmp->val);
            mp[tmp] = 1;
        }
        if(tmp->right)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    for (int i = vec.size()-1; i >= 0;--i)
        ans.push_back(vec[i]);
    return ans;
}
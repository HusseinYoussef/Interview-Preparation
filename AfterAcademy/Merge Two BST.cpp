#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorder(vector<int> &v, TreeNode* node)
{
    if(node == nullptr)
        return;
    
    inorder(v, node->left);
    v.push_back(node->val);
    inorder(v, node->right);
}

vector<int> mergeTwoBST(TreeNode* bst1, TreeNode* bst2)
{
    vector<int> l;
    vector<int> r;
    vector<int> ans;
    inorder(l, bst1);
    inorder(r, bst2);
    
    int i = 0, j = 0;
    while(i < l.size() && j < r.size())
    {
        if(l[i] < r[j])
            ans.push_back(l[i++]);
        else
            ans.push_back(r[j++]);
    }
    while(i < l.size())
        ans.push_back(l[i++]);
    while(j < r.size())
        ans.push_back(r[j++]);
    return ans;
}
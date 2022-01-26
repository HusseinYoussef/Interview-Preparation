#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(vector<int> &nodes, TreeNode* node)
{
    if(node == nullptr)
        return;
    inorder(nodes, node->left);
    nodes.push_back(node->val);
    inorder(nodes, node->right);
}

vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
{
    vector<int> t1, t2;
    inorder(t1, root1);
    inorder(t2, root2);
    vector<int> ans;
    int i, j;
    for (i = 0, j = 0; i < t1.size() && j < t2.size();)
    {
        if(t1[i] < t2[j])
            ans.push_back(t1[i++]);
        else
            ans.push_back(t2[j++]);
    }
    while(i < t1.size())
        ans.push_back(t1[i++]);
    while(j < t2.size())
        ans.push_back(t2[j++]);
    return ans;
}
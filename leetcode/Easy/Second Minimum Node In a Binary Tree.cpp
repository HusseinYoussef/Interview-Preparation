#include <iostream>
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

int mn1 = -1;
int mn2 = -1;

void dfs(TreeNode* node)
{
    if(!node)
        return;

    if(mn1 == -1 || node->val < mn1)
    {
        mn2 = mn1;
        mn1 = node->val;
    }
    else if((mn2 == -1 || node->val < mn2) && node->val != mn1)
        mn2 = node->val;
    
    dfs(node->right);
    dfs(node->left);
}

int findSecondMinimumValue(TreeNode* root)
{
    dfs(root);
    return mn2;
}

int main()
{
    return 0;
}
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rec(TreeNode* node)
{
    if(!node)
        return;
    TreeNode *tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    rec(node->left);
    rec(node->right);
}

TreeNode* invertTree(TreeNode* root) {

    rec(root);
    return root;

    // Iterative solution
    
    // stack<TreeNode *> st;
    // st.push(root);
    // while(st.size())
    // {
    //     TreeNode *node = st.top();
    //     st.pop();
    //     if(!node)
    //         continue;
    //     TreeNode *tmp = node->left;
    //     node->left = node->right;
    //     node->right = tmp;
    //     st.push(node->left);
    //     st.push(node->right);
    // }
    // return root;
}

int main()
{
    return 0;
}
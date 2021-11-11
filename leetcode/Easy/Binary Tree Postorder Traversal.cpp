#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> ans;

void rec(TreeNode* node)
{
    if(node == nullptr)
        return;

    rec(node->left);
    rec(node->right);
    ans.push_back(node->val);
}
vector<int> inorderTraversal(TreeNode* root)
{
    // rec(root);
    // return ans;

    // O(N)
    vector<int> vec;
    stack<TreeNode*> st;
    
    if(root)
        st.push(root);
    while(st.size())
    {
        TreeNode *top = st.top();
        if(top->left)
        {
            st.push(top->left);
            top->left = nullptr;
        }
        else
        {
            if(top->right)
            {
                st.push(top->right);
                top->right = nullptr;
            }
            else
            {
                st.pop();
                vec.push_back(top->val);
            }
        }
    }
    return vec;
}

int main()
{
    TreeNode *head = new TreeNode(1);
    head->right = new TreeNode(2);
    head->right->left = new TreeNode(3);
    inorderTraversal(head);
    return 0;
}
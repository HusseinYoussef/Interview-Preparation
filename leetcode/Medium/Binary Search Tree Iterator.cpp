#include <iostream>
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

class BSTIterator {
public:
    stack<TreeNode *> st;
    BSTIterator(TreeNode* root)
    {
        findLeft(root);
    }

    void findLeft(TreeNode*node)
    {
        while(node)
        {
            st.push(node);
            node = node->left;
        }
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();
        findLeft(node->right);
        return node->val;
    }
    
    bool hasNext()
    {
        return !st.empty();
    }
};
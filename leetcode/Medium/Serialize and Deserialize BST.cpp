#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    string s;
    void preorder(TreeNode* node)
    {
        if (node == nullptr)
            return;
        if(s.size())
            s += "|";
        s += to_string(node->val);
        preorder(node->left);
        preorder(node->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        s = "";
        preorder(root);
        return s;
    }

    TreeNode* build(TreeNode* node, int val)
    {
        if(node == nullptr)
            return new TreeNode(val);
        if(val < node->val)
            node->left = build(node->left, val);
        else
            node->right = build(node->right, val);
        return node;
    }

    // Decodes your encoded data to tree.
    // Insert each val in the tree
    TreeNode* deserialize(string data)
    {
        TreeNode *root = nullptr;
        int num = 0;
        for (int i = 0;i<data.size();++i)
        {
            if(isdigit(data[i]))
                num = num * 10 + (data[i] - '0');
            if(data[i] == '|' || i == data.size()-1)
            {
                root = build(root, num);
                num = 0;
            }
        }
        return root;
    }
};
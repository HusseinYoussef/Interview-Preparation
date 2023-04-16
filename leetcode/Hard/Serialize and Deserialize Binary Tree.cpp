#include <vector>
#include <cstring>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void preorder(TreeNode* node, string &encoding)
    {
        if (encoding.size() != 0)
            encoding += ",";

        if (!node)
        {
            encoding += "#";
            return;
        }

        encoding += to_string(node->val);
        preorder(node->left, encoding);
        preorder(node->right, encoding);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        string s = "";
        preorder(root, s);
        return s;
    }
    
    vector<string> split(string encoding)
    {
        vector<string> vec;
        string tmp = "";
        for(int i = 0;i<encoding.size();++i)
        {
            if (encoding[i] == ',')
            {
                vec.push_back(tmp);
                tmp = "";
                continue;
            }
            tmp += encoding[i];
        }
        if (tmp.size())
            vec.push_back(tmp);
        
        return vec;
    }

    int idx = 0;
    TreeNode* build(vector<string> &parts)
    {
        if(idx >= parts.size() || parts[idx] == "#")
        {
            ++idx;
            return nullptr;
        }

        int val = stoi(parts[idx++]);
        TreeNode* node = new TreeNode(val);
        node->left = build(parts);
        node->right = build(parts);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        vector<string> parts = split(data);
        idx = 0;
        TreeNode* root = build(parts);
        
        return root;
    }
};

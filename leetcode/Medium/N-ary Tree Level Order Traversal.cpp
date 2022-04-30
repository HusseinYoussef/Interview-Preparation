#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


vector<vector<int>> levelOrder(Node* root)
{
    if(root == nullptr)
        return {};

    vector<vector<int>> ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        int lvlsz = q.size();
        vector<int> lvl;
        for (int i = 0; i < lvlsz;++i)
        {
            Node *node = q.front();
            q.pop();
            lvl.push_back(node->val);
            for (int j = 0; j < node->children.size();++j)
            {
                q.push(node->children[j]);
            }
        }
        if(lvl.size())
            ans.push_back(lvl);
    }
    return ans;
}
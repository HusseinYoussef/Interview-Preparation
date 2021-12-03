#include <iostream>
#include <vector>

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

int dfs(Node* node)
{
    if(!node)
        return 0;
    if(node->children.size() == 0)
        return 1;

    int mx = 0;
    for (int i = 0; i < node->children.size();++i)
    {
        mx = max(mx, dfs(node->children[i]) + 1);
    }
    return mx;
}

int maxDepth(Node* root)
{
    return dfs(root);
}

#include <iostream>
#include <vector>

using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* mp[105];
    void dfs(Node* node)
    {
        if (mp[node->val] == nullptr)
        {
            Node* tmp = new Node(node->val);
            mp[node->val] = tmp;
        }
        Node* cpyNode = mp[node->val];

        for (int i = 0;i<node->neighbors.size();++i)
        {
            Node* child = node->neighbors[i];

            if (mp[child->val] == nullptr)
                dfs(child);

            if (mp[child->val] != nullptr)
                cpyNode->neighbors.push_back(mp[child->val]);
        }
    }

    Node* cloneGraph(Node* node)
    {
        if (!node)
            return nullptr;

        for(int i = 0;i<105;++i)
            mp[i] = nullptr;

        dfs(node);
        return mp[node->val];
    }
};

#include <iostream>
#include <vector>

using namespace std;

class Node
{
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

Node *arr[105];
void copy(Node* node, Node* cpy)
{
    arr[cpy->val] = cpy;
    for (int i = 0; i < node->neighbors.size();++i)
    {
        if(arr[node->neighbors[i]->val] == nullptr)
        {
            Node *tmp = new Node(node->neighbors[i]->val);
            cpy->neighbors.push_back(tmp);
            copy(node->neighbors[i], tmp);
        }
        else
        {
            cpy->neighbors.push_back(arr[node->neighbors[i]->val]);
        }
    }
}

Node* cloneGraph(Node* node)
{
    if(!node)
        return nullptr;
    for (int i = 0; i < 105;++i)
        arr[i] = nullptr;
    Node *cpy = new Node(node->val);
    copy(node, cpy);
    return cpy;
}
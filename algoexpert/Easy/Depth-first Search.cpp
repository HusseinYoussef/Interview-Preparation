
/*
Problem Statement


  Implement the depthFirstSearch methon in Node class, which takes in an empty array, traverses the tree
  using the Depth-first Search approach (specifically navigating the tree from
  (left to right), stores all of the nodes' names in the input array, and returns it.
*/

#include <iostream>
#include <vector>
using namespace std;

// Do not edit the class below except
// for the depthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node
{
    public:
    string name;
    vector<Node *> children;

    Node(string str) { name = str; }

    // Preorder Traversal
    void dfs(Node *node, vector<string> *array)
    {
        if(node == nullptr)
            return;
        array->push_back(node->name);
        for (int i = 0; i < node->children.size();++i)
            dfs(node->children[i], array);
    }

    vector<string> depthFirstSearch(vector<string> *array)
    {
        dfs(this, array);
        return *array;
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};
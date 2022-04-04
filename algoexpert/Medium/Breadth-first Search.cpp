
/*
    Problem Statement

    BFS
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Do not edit the class below except
// for the breadthFirstSearch method.
// Feel free to add new properties
// and methods to the class.
class Node {
public:
  string name;
  vector<Node *> children;

  Node(string str) { name = str; }

  vector<string> breadthFirstSearch(vector<string> *array)
  {
      queue<Node*> q;
      q.push(this);
      while(!q.empty())
      {
          Node *node = q.front();
          q.pop();
          for (int i = 0; i < node->children.size();++i)
              q.push(node->children[i]);
          array->push_back(node->name);
      }
      return *array;
  }

  Node *addChild(string name) {
    Node *child = new Node(name);
    children.push_back(child);
    return this;
  }
};

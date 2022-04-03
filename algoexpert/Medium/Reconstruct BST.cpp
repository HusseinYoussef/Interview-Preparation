
/*
    Problem Statement

    Given a non-empty array of integers representing the pre-order traversal of a
    Binary Search Tree (BST), write a function that creates the relevant BST and
    returns its root node.
*/

#include <vector>
#include <climits>
using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

int idx;
BST* rec(vector<int> &preorder, int mn = INT_MIN, int mx = INT_MAX)
{
    // lower bound <= value < upper bound
    if(idx == preorder.size() || preorder[idx] >= mx || preorder[idx] < mn)
        return nullptr;

    BST *node = new BST(preorder[idx++]);

    node->left = rec(preorder, mn, node->value);
    node->right = rec(preorder, node->value, mx);
    return node;
}

BST *reconstructBst(vector<int> preOrderTraversalValues)
{
    if(preOrderTraversalValues.size() == 0)
        return nullptr;
    idx = 0;
    return rec(preOrderTraversalValues);
}
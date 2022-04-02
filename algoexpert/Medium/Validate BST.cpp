
/*
    Problem Statement

    Write a function that takes in a potentially invalid Binary Search Tree (BST)
    and returns a boolean representing whether the BST is valid.
*/

#include <iostream>
#include <climits>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool ans = 1;
// max, min
pair<int, int> rec(BST *node)
{
    if(node == nullptr)
        return {-1e8, 1e8};

    // max, min in left subtree
    pair<int, int> l = rec(node->left);
    // max, min in right subtree
    pair<int, int> r = rec(node->right);
    
    ans &= (node->value > l.first) && (node->value <= r.second);
    return {max(node->value, r.first), min(node->value, l.second)};
}

// Better solution
bool rec(BST *tree, int mn=INT_MIN, int mx=INT_MAX)
{
		if(tree == nullptr)
			return true;
		
		bool l = rec(tree->left, mn, tree->value);
		bool r = rec(tree->right, tree->value, mx);
		return l && r && tree->value >= mn && tree->value < mx;
}

bool validateBst(BST *tree)
{
    rec(tree);
    return ans;
}
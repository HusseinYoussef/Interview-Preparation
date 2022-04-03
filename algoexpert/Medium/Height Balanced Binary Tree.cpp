
/*
    Problem Statement

    You're given the root node of a Binary Tree. Write a function that returns True if this Binary Tree is height balanced and
    false otherwise.
    
    A Binary Tree is height balanced if for each node in the tree, the difference
    between the height of its left subtree and the height of its right subtree is
    at most 1.
*/

#include <iostream>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;

  BinaryTree(int value) { this->value = value; }
};

// O(n) Time, O(h) Space
bool ans = 1;
int rec(BinaryTree *node)
{
    if (node == nullptr)
        return 0;

    int lheight = rec(node->left);
    int rheight = rec(node->right);

    ans &= abs(lheight - rheight) <= 1;
    return max(lheight, rheight) + 1;
}

bool heightBalancedBinaryTree(BinaryTree *tree)
{
    ans = 1;
    rec(tree);
    return ans;
}

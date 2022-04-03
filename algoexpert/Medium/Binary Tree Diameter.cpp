
/*
    Problem Statement

    Write a function that takes in a Binary Tree and returns its diameter. The
    diameter of a binary tree is defined as the length of its longest path, even
    if that path doesn't pass through the root of the tree.

    A path is a collection of connected nodes in a tree, where no node is
    connected to more than two other nodes. The length of a path is the number of
    edges between the path's first node and its last node.
*/

#include <iostream>
using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

int ans = 0;
int rec(BinaryTree * node)
{
    if(node == nullptr)
        return 0;

    int ldepth = rec(node->left);
    int rdepth = rec(node->right);
    ans = max(ans, ldepth + rdepth);
    return max(ldepth, rdepth) + 1;
}

int binaryTreeDiameter(BinaryTree *tree)
{
    ans = 0;
    rec(tree);
    return ans;
}
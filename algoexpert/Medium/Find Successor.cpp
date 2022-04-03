
/*
    Problem Statement

    Write a function that takes in a Binary Tree (where nodes have an additional
    pointer to their parent node) as well as a node contained in that tree and
    returns the given node's successor.

    A node's successor is the next node to be visited (immediately after the given
    node) when traversing its tree using the in-order tree-traversal technique. A
    node has no successor if it's the last node to be visited in the in-order
    traversal.

    If a node has no successor, your function should return Null 
*/

using namespace std;

// This is an input class. Do not edit.
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

// Solution 1: O(h) Time, O(1) Space
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node)
{
    BinaryTree *tmp, *pre;
    if(node->right)
    {
        tmp = node->right;
        while(tmp->left)
            tmp = tmp->left;
        return tmp;
    }
    else
    {
        tmp = node->parent, pre = node;
        while(tmp)
        {
            if(tmp->left == pre)
                return tmp;
            pre = tmp;
            tmp = tmp->parent;
        }
    }
    return nullptr;
}

// Solution 2: O(n) Time, O(h) Space

// BinaryTree *ans = nullptr, *pre = nullptr;
// void inorder(BinaryTree *cur, BinaryTree *node)
// {
//     if(cur == nullptr || ans)
//         return;

//     inorder(cur->left, node);
//     if(pre == node)
//         ans = cur;
//     pre = cur;
//     inorder(cur->right, node);
// }

// BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node)
// {
//     ans = pre = nullptr;
//     inorder(tree, node);
//     return ans;
// }
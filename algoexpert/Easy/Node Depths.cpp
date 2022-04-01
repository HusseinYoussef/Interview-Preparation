
/*
    Problem Statement

    Write a function that takes in a Binary Tree and returns the sum of its nodes'
    depths.
*/

using namespace std;

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

int dfs(BinaryTree *node, int depth)
{
    if(node == nullptr)
        return 0;

    return dfs(node->left, depth + 1) + dfs(node->right, depth + 1) + depth;
}

int nodeDepths(BinaryTree *root)
{
    return dfs(root, 0);
}

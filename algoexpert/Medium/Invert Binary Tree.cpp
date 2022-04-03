
/*
    Problem Statement

    Write a function that takes in a Binary Tree and inverts it. In other words,
    the function should swap every left node in the tree for its corresponding
    right node.
*/

#include <vector>
#include <stack>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void rec(BinaryTree *node)
{
    if(node == nullptr)
        return;

    swap(node->left, node->right);
    rec(node->left);
    rec(node->right);
}

void invertBinaryTree(BinaryTree *tree)
{
    rec(tree);

    // solution 2 Iterative
    stack<BinaryTree *> st;
	st.push(tree);
	while(st.size())
	{
		BinaryTree * node = st.top();
		st.pop();
		swap(node->left, node->right);
		if(node->left)
			st.push(node->left);
		if(node->right)
			st.push(node->right);
	}
}
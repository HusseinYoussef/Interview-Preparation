
/*
    Problem Statement

    Write a function that takes in a Binary Search Tree (BST) and a positive
    integer k  and returns the kth largest integer contained in the BST.
*/

using namespace std;

// This is an input class. Do not edit.
class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

int cnt;
int ans = -1;
void reverseInOrder(BST *tree, int k)
{
    if(tree == nullptr || cnt > k)
        return;

    reverseInOrder(tree->right, k);
    if(cnt == k)
        ans = tree->value;
		++cnt;
    reverseInOrder(tree->left, k);
}

int findKthLargestValueInBst(BST *tree, int k)
{
    cnt = 1;
    reverseInOrder(tree, k);
    return ans;
}
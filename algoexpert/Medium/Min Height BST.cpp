
/*
    Problem Statement (Construct BST from sorted array)

    Write a function that takes in a non-empty sorted array of distinct integers,
    constructs a BST from the integers, and returns the root of the BST.
*/

#include <vector>
using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

BST * rec(vector<int> &array, int l, int r)
{
    if(r < l)
        return nullptr;

    int mid = l + (r - l) / 2;
    BST *node = new BST(array[mid]);
    node->left = rec(array, l, mid - 1);
    node->right = rec(array, mid + 1, r);
    return node;
}

BST *minHeightBst(vector<int> array)
{
    return rec(array, 0, array.size() - 1);
}

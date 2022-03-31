
/*
    Problem Statement
    
    Write a function that takes in a Binary Search Tree (BST) and a target integer
    value and returns the closest value to that target value contained in the BST.

*/

#include <iostream>

class BST
{
    public:
        int value;
        BST *left;
        BST *right;

        BST(int val);
        BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target)
{
    BST *tmp = tree;
    int ans = 1e8;
    while(tmp)
    {
        if(abs(tmp->value - target) < abs(ans - target))
            ans = tmp->value;

        if(tmp->value == target)
            break;
        else if(tmp->value < target)
            tmp = tmp->right;
        else
            tmp = tmp->left;
    }
    return ans;
}

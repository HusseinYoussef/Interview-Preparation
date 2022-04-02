
/*
Problem Statement

*/
#include <vector>
using namespace std;

// Do not edit the class below except for
// the insert, contains, and remove methods.
// Feel free to add new properties and methods
// to the class.
class BST {
    public:
    int value;
    BST *left;
    BST *right;

    BST(int val)
    {
        value = val;
        left = nullptr;
        right = nullptr;
    }

    BST &insert(int val)
    {
        BST *tmp = this, *pre = nullptr;
        while(tmp)
        {
            pre = tmp;
            if(tmp->value <= val)
                tmp = tmp->right;
            else
                tmp = tmp->left;
        }
        if(pre->value <= val)
            pre->right = new BST(val);
        else
            pre->left = new BST(val);
        return *this;
    }

    bool contains(int val)
    {
        BST *tmp = this;
        while(tmp)
        {
            if(tmp->value == val)
                return true;
            else if(tmp->value < val)
                tmp = tmp->right;
            else
                tmp = tmp->left;
        }
        return false;
    }

    BST &remove(int val, BST* parent = nullptr)
    {
        BST *tmp = this;
        while(tmp)
        {
            if(tmp->value < val)
            {
                parent = tmp;
                tmp = tmp->right;
            }
            else if(tmp->value > val)
            {
                parent = tmp;
                tmp = tmp->left;
            }
            else
            {
                // Case 1: leaf node
                if (tmp->left == nullptr && tmp->right == nullptr)
                {
                    if(parent)
                    {
                        if(parent->left == tmp)
                            parent->left = nullptr;
                        else
                            parent->right = nullptr;
                    }
                    else
                    {
                        // one node tree
                    }
                }
                // Case 2: one child branch
                else if(tmp->left == nullptr || tmp->right == nullptr)
                {
                    if(tmp->left)
                    {
                        if(parent)
                        {
                            if(parent->left == tmp)
                                parent->left = tmp->left;
                            if(parent->right == tmp)
                                parent->right = tmp->left;
                        }
                        else
                            *this  = *tmp->left;
                    }
                    else
                    {
                        if(parent)
                        {
                            if(parent->left == tmp)
                                parent->left = tmp->right;
                            if(parent->right == tmp)
                                parent->right = tmp->right;
                        }
                        else
                            *this = *tmp->right;
                    }
                }
                // Case 3: two child branches, pick smallest value in right subtree
                else
                {
                    BST *node = tmp->right;
                    while(node->left)
                        node = node->left;
                    tmp->value = node->value;
                    tmp->right->remove(node->value, tmp);
                }
                break;
            }
        }
        return *this;
    }
};
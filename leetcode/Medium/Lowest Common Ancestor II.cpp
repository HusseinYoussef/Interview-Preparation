#include <iostream>

using namespace std;

class ParentTreeNode
{
    public:
        int val;
        ParentTreeNode *parent, *left, *right;
};

ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B)
{
    // Same as Linked List intersection
    ParentTreeNode *tmp1 = A, *tmp2 = B;
    while(tmp1 != tmp2)
    {
        tmp1 = tmp1->parent;
        tmp2 = tmp2->parent;
        if(tmp1 == nullptr)
            tmp1 = B;
        if(tmp2 == nullptr)
            tmp2 = A;
    }
    return tmp1;
}
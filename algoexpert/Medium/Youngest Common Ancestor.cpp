
/*
    Problem Statement (Intersection of Two Linked Lists)


    Write a function that returns the youngest common ancestor to the two
    descendants.
*/

#include <vector>
using namespace std;

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
                                         AncestralTree *descendantTwo) {

    AncestralTree *a = descendantOne, *b = descendantTwo;
    while(a || b)
    {
        if(a == nullptr)
            a = descendantTwo;
        if(b == nullptr)
            b = descendantOne;

        if(a == b)
            return a;

        a = a->ancestor;
        b = b->ancestor;
    }
    return nullptr;
}

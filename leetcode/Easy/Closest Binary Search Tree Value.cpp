#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class TreeNode {
 public:
     int val;
     TreeNode *left, *right;
     TreeNode(int val) {
         this->val = val;
         this->left = this->right = NULL;
     }
};

double mn = INT_MAX;
int ans = -1;
void rec(TreeNode * node, double target)
{
    if(!node)
        return;
    if(abs(node->val - target) < mn)
    {
        mn = node->val;
        ans = node->val;
    }
    rec(node->left, target);
    rec(node->right, target);
}

int closestValue(TreeNode * root, double target)
{
    rec(root, target);
    return ans;
}
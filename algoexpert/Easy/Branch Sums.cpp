
/*
    Problem Statement
    
    Write a function that takes in a Binary Tree and returns a list of its branch
    sums ordered from leftmost branch sum to rightmost branch sum.
*/

#include <vector>

using namespace std;

class BinaryTree
{
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

void dfs(vector<int> &ans, BinaryTree *node, int sum)
{
    if(node == nullptr)
        return;
    if(node->left == nullptr && node->right == nullptr)
    {
        ans.push_back(sum + node->value);
        return;
    }

    sum += node->value;
    dfs(ans, node->left, sum);
    dfs(ans, node->right, sum);
}

vector<int> branchSums(BinaryTree *root)
{
    vector<int> ans;
    dfs(ans, root, 0);
    return ans;
}
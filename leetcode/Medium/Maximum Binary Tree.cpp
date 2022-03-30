#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time : O(n^2), Space : O(n) 
TreeNode* rec(vector<int>& nums, int l, int r)
{
    if(r < l)
        return nullptr;

    int mxidx = l;
    for (int i = l; i <= r;++i)
    {
        if(nums[i] > nums[mxidx])
            mxidx = i;
    }
    TreeNode *node = new TreeNode(nums[mxidx]);
    node->left = rec(nums, l, mxidx - 1);
    node->right = rec(nums, mxidx + 1, r);
    return node;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums)
{
    return rec(nums, 0, nums.size() - 1);
}
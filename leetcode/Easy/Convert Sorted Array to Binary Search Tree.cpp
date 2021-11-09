#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
struct StackNode {
    int i;
    int j;
    TreeNode *root;
    StackNode(TreeNode* node, int left, int right) : root(node), i(left), j(right) {}
};

TreeNode* rec(vector<int>& nums, int i, int j)
{
    if(i > j)
        return nullptr;

    int mid = (i + j) / 2;
    TreeNode *node = new TreeNode(nums[mid]);
    node->left = rec(nums, i, mid - 1);
    node->right = rec(nums, mid + 1, j);
    return node;
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    return rec(nums, 0, nums.size() - 1);

    // stack<StackNode> l, r;
    // int mid = nums.size() / 2;
    // TreeNode *head = new TreeNode(nums[mid]);
    // l.push(StackNode(head, 0, mid - 1));
    // r.push(StackNode(head, mid + 1, nums.size() - 1));
    // while(l.size() || r.size())
    // {
    //     if(l.size())
    //     {
    //         StackNode node = l.top();
    //         l.pop();
    //         if(node.i <= node.j)
    //         {
    //             mid = (node.i + node.j) / 2;
    //             node.root->left = new TreeNode(nums[mid]);
    //             l.push(StackNode(node.root->left, node.i, mid - 1));
    //             r.push(StackNode(node.root->left, mid + 1, node.j));
    //         }
    //     }
    //     if(r.size())
    //     {
    //         StackNode node = r.top();
    //         r.pop();
    //         if(node.i <= node.j)
    //         {
    //             mid = (node.i + node.j) / 2;
    //             node.root->right = new TreeNode(nums[mid]);
    //             l.push(StackNode(node.root->right, node.i, mid - 1));
    //             r.push(StackNode(node.root->right, mid + 1, node.j));
    //         }
    //     }
    // }
    // return head;
}

int main()
{
    vector<int> vec = {-10,-3,0,5,9};
    sortedArrayToBST(vec);
    return 0;
}
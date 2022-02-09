#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

ListNode *mid(ListNode* head)
{
    ListNode * walker = head, *runner = head->next;
    ListNode * pre = nullptr;
    while(runner && runner->next)
    {
        pre = walker;
        walker = walker->next;
        runner = runner->next->next;
    }
    if(pre)
        pre->next = nullptr;
    return walker; 
}

TreeNode* sortedListToBST(ListNode* head)
{
    if(head == nullptr)
        return nullptr;

    ListNode* middle = mid(head);
    TreeNode* node = new TreeNode(middle->val);
    node->left = sortedListToBST((head == middle)? nullptr:head);
    node->right = sortedListToBST(middle->next);
    return node;
}

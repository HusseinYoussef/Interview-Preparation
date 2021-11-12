#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* rec(ListNode* node, ListNode* pre=nullptr)
{
    if(!node)
        return nullptr;

    ListNode *ans = rec(node->next, node);
    node->next = pre;
    return ans ? ans : node;
}

ListNode* reverseList(ListNode* head)
{
    // return rec(head);

    ListNode *pre = nullptr;
    while(head)
    {
        ListNode *tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return pre;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    reverseList(head);
    return 0;
}
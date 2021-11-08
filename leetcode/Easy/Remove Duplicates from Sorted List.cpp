#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode *cur = head, *iter = head? head->next:nullptr;
    while(iter != nullptr)
    {
        if(iter->val != cur->val)
        {
            cur->next = iter;
            cur = iter;
        }
        iter = iter->next;
    }
    if(cur)
        cur->next = nullptr;
    return head;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    deleteDuplicates(head);
    return 0;
}
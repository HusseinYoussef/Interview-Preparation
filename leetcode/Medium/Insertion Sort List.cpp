#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head)
{
    // O(1) Space
    if(head == nullptr)
        return nullptr;
    
    ListNode* cur = head->next;
    head->next = nullptr;
    while(cur)
    {
        ListNode* l = head, *pre = nullptr, *nxt = cur->next;
        while(l && l->val < cur->val)
        {
            pre = l;
            l = l->next;
        }
        cur->next = l;
        if(pre)
            pre->next = cur;
        else
            head = cur;

        cur = nxt;
    }
    return head;

    // O(N) Space
    ListNode* cur = head, * newHead = nullptr;
    while(cur)
    {
        ListNode* iter = newHead;
        ListNode* pre = nullptr;
        while(iter && iter->val < cur->val)
        {
            pre = iter;
            iter = iter->next;
        }
        if(pre == nullptr)
            newHead = new ListNode(cur->val, iter);
        else
            pre->next = new ListNode(cur->val, iter);
        cur = cur->next;
    }
    return newHead;
}

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head)
{
    ListNode *pre = nullptr, *cur = head;
    while(cur && cur->next)
    {
        ListNode *nxt = cur->next;
        cur->next = nxt->next;
        nxt->next = cur;
        if(pre == nullptr)
            head = nxt;
        else
            pre->next = nxt;

        pre = cur;
        cur = cur->next;
    }
    return head;
}
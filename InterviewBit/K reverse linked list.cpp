#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head, int k)
{
    ListNode *cur = head, *prev = nullptr;
    while(cur)
    {
        ListNode *pre = nullptr, *tmp = cur;
        for (int i = 0; i < k;++i)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        if(prev)
            prev->next = pre;
        else
            head = pre;
        prev = tmp;
    }
    return head;
}
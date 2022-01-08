#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right)
{
    ListNode *t1 = nullptr, *t2 = nullptr, *tmp;
    ListNode *pre = nullptr, *cur = head;
    int i = 0;
    while(cur)
    {
        ++i;
        if(i == left)
        {
            t1 = pre, t2 = cur;
        }
        pre = cur;
        cur = cur->next;

        if(i == left)
        {
            for (i = 0; i < right - left; ++i)
            {
                tmp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = tmp;
            }
            if(t1)
                t1->next = pre;
            t2->next = cur;
            if(left == 1)
                head = pre;
            break;
        }
    }
    return head;
}
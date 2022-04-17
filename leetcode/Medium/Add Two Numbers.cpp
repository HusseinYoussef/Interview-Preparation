#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy, *l = l1, *r = l2;

    bool c = 0;
    while(l || r)
    {
        int d1 = 0, d2 = 0;
        if(l)
            d1 = l->val;
        if(r)
            d2 = r->val;

        int sum = d1 + d2 + c;
        c = sum >= 10;
        sum %= 10;

        if(l)
        {
            l->val = sum;
            cur->next = l;
        }
        else
        {
            r->val = sum;
            cur->next = r;
        }

        if(l)
            l = l->next;
        if(r)
            r = r->next;
        cur = cur->next;
    }
    if(c)
        cur->next = new ListNode(1);
    return dummy->next;
}
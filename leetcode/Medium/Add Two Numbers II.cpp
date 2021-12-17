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

ListNode *reverse(ListNode* head)
{
    ListNode *pre = nullptr, *cur = head;
    while(cur)
    {
        ListNode *tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
    }
    return pre;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *h1 = reverse(l1), *h2 = reverse(l2), *pre = nullptr;
    ListNode *tmp = h1;
    int d1 , d2 , carry = 0;
    while(h1 || h2)
    {
        d1 = 0, d2 = 0;
        if(h1 != nullptr)
            d1 = h1->val;
        if(h2 != nullptr)
            d2 = h2->val;

        int sum = d1 + d2 + carry;
        carry = sum >= 10;
        if(h1 != nullptr)
        {
            h1->val = carry ? sum % 10 : sum;
            pre = h1;
        }
        else
        {
            ListNode* node = new ListNode(carry ? sum % 10 : sum);
            pre->next = node;
            pre = node;
        }
        h1 = h1 ? h1->next : nullptr;
        h2 = h2 ? h2->next : nullptr;
    }
    if(carry)
    { 
        if(h1 != nullptr)
            h1->val = carry;
        else
        {
            ListNode* node = new ListNode(carry);
            pre->next = node;
        }
    }
    return reverse(tmp);
}
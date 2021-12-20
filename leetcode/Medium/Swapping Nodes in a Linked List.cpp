#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapNodes(ListNode* head, int k)
{
    ListNode *l = nullptr, *r = nullptr, *cur = head;
    int i = 1;
    while(cur)
    {
        if(r)
            r = r->next;
        if(i == k)
            l = cur, r = head;
        cur = cur->next;
        ++i;
    }
    swap(l->val, r->val);
    return head;
}
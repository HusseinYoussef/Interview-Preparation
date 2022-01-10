#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* getMid(ListNode* head)
{
    ListNode *walker = head, *runner = head->next;
    while(runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
    }
    ListNode *midNext = walker->next;
    walker->next = nullptr;
    return midNext;
}

ListNode* merge(ListNode* l, ListNode* r)
{
    ListNode tmpHead(0);
    ListNode *tmp = &tmpHead;
    while(l && r)
    {
        if(l->val < r->val)
        {
            tmp->next = l;
            l = l->next;
        }
        else
        {
            tmp->next = r;
            r = r->next;
        }
        tmp = tmp->next;
    }
    if(l)
        tmp->next = l;
    else
        tmp->next = r;
    return tmpHead.next;
}

ListNode* sortList(ListNode* head)
{
    if(head == nullptr || head->next == nullptr)
        return head;

    ListNode *mid = getMid(head);
    ListNode *l = sortList(head);
    ListNode *r = sortList(mid);
    return merge(l, r);
}
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head)
{
    if (!head)
        return nullptr;
    ListNode *cur = head, *pre = nullptr, *tmp = head->next;
    bool f = 0;
    while(cur->next)
    {
        ListNode *nxt = cur->next;
        cur->next = cur->next->next;
        pre = cur;
        cur = nxt;
        f = !f;
    }
    if(f) pre->next = tmp;
    else
        cur->next = tmp;
    return head;
}
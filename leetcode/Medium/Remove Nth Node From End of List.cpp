#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *tmp = head;
    ListNode *cur = nullptr, *pre = nullptr;
    int i = 0;
    while(tmp)
    {
        ++i;
        tmp = tmp->next;
        if(cur)
        {
            pre = cur;
            cur = cur->next;
        }
        if(i == n)
        {
            cur = head;
            pre = nullptr;
        }
    }
    if(pre == nullptr)
        head = head->next;
    else
        pre->next = cur->next;
    return head;
}
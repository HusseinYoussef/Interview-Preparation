#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* partition(ListNode* head, int x)
{
    ListNode *dummy1 = new ListNode(0), *dummy2 = new ListNode(0);
    ListNode *d1 = dummy1, *d2 = dummy2;
    while(head)
    {
        if(head->val < x)
        {
            d1->next = head;
            d1 = head;
        }
        else
        {
            d2->next = head;
            d2 = head;
        }
        head = head->next;
    }
    d2->next = nullptr;
    d1->next = dummy2->next;
    return dummy1->next;
}
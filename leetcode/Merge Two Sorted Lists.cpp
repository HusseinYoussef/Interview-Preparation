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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
    ListNode *head = nullptr;
    ListNode *cur = nullptr;

    while (l1 != nullptr && l2 != nullptr)
    {
        if(head == nullptr)
        {
            head = new ListNode;
            cur = head;
        }
        else
        {
            cur->next = new ListNode;
            cur = cur->next;
        }

        if(l1->val < l2->val)
        {
            cur->val = l1->val;
            l1 = l1->next;
        }
        else
        {
            cur->val = l2->val;
            l2 = l2->next;
        }
    }
    while (l1 != nullptr)
    {
        if(head == nullptr)
        {
            head = new ListNode;
            cur = head;
        }
        else
        {
            cur->next = new ListNode;
            cur = cur->next;
        }
        cur->val = l1->val;
        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        if(head == nullptr)
        {
            head = new ListNode;
            cur = head;
        }
        else
        {
            cur->next = new ListNode;
            cur = cur->next;
        }
        cur->val = l2->val;
        l2 = l2->next;
    }
    return head;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(2);
    l2->next->next = new ListNode(3);
    mergeTwoLists(l1, l2);
    return 0;
}
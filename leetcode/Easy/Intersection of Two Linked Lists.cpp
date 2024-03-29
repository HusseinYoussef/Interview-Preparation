#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *a = headA, *b = headB;
    while(a != b)
    {
        a = a == nullptr ? headB : a->next;
        b = b == nullptr ? headA : b->next;
    }
    return a;
}

int main()
{
    return 0;
}
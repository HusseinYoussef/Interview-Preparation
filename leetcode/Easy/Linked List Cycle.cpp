#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Use two pointers, walker and runner.
// walker moves step by step. runner moves two steps at time.
// if the Linked List has a cycle walker and runner will meet at some
// point.
bool hasCycle(ListNode *head)
{
    ListNode *l = head, *r = head;
    while(l && r && r->next)
    {
        l = l->next;
        r = r->next->next;
        if(l == r)
            return true;
    }
    return false;
}

int main()
{
    return 0;
}
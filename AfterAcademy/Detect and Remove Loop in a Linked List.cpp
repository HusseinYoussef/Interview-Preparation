
using namespace std;

typedef struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int v)
    {
        val = v;
        next = nullptr;
    }
} ListNode;

ListNode* detectAndRemoveLoop(ListNode* head)
{
    ListNode *walker = head, *runner = head;
    while(runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
        if(walker == runner)
            break;
    }

    // No loop
    if(runner && walker != runner)
        return head;

    walker = head;
    ListNode *pre = nullptr;
    // find first node in loop, so pre will be the last node in loop
    while(walker != runner)
    {
        pre = runner;
        walker = walker->next;
        runner = runner->next;
    }
    pre->next = nullptr;
    return head;
}
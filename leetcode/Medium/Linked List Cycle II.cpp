#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head)
{
    // Floyd's Cycle Detection
    ListNode *walker = head, *runner = head;
    while(runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
        if(runner == walker)
            break;
    }
    if(runner == nullptr || runner->next == nullptr)
        return nullptr;
    walker = head;
    while(walker != runner)
    {
        walker = walker->next;
        runner = runner->next;
    }
    return walker;
}
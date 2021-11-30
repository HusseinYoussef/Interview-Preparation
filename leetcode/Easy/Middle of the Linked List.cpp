#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head)
{
    ListNode *walker = head, *runner = head;
    while(runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
    }
    return walker;
}

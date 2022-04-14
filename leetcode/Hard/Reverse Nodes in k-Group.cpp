#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k)
{
    ListNode *runner = head;
    int cnt = 1;
    while(runner && cnt < k)
    {
        runner = runner->next;
        ++cnt;
    }

    ListNode *cur = head, *prev = nullptr;
    while(runner)
    {
        ListNode *pre = nullptr, *tmp = cur;
        for (int i = 0; i < k;++i)
        {
            ListNode *nxt = cur->next, *nxtrun = (runner) ? runner->next : nullptr;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            runner = nxtrun;
        }
        if(prev)
            prev->next = pre;
        else
            head = pre;
        prev = tmp;
    }
    if(prev)
        prev->next = cur;
    return head;
}
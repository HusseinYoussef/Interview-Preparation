#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* pre = nullptr, * cur = head;
    while(cur)
    {
        if(cur->next && cur->val == cur->next->val)
        {
            while(cur->next && cur->val == cur->next->val)
                cur = cur->next;
            cur = cur->next;
            continue;
        }
        if(pre == nullptr)
            head = cur;
        else
            pre->next = cur;
        pre = cur;
        cur = cur->next;
    }
    if(pre == nullptr)
        return nullptr;
    pre->next = nullptr;
    return head;
}

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val)
{
    ListNode *cur = head, *pre = nullptr;
    while(cur)
    {
        if(cur->val == val)
        {
            if(cur == head)
            {
                head = head->next;
            }
            if(pre)
            {
                pre->next = cur->next;
            }
        }
        else
        {
            pre = cur;
        }
        cur = cur->next;
    }
    return head;
}

int main()
{
    return 0;
}
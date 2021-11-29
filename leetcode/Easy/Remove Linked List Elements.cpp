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
            // Head to be moved
            if(pre == nullptr)
            {
                head = head->next;
            }
            else
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
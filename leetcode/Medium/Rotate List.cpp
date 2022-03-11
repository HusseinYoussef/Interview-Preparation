#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* cur, ListNode* end=nullptr)
{
    ListNode *pre = nullptr;
    while(cur && cur != end)
    {
        ListNode *nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }
    return pre;
}

ListNode* rotateRight(ListNode* head, int k)
{
    if(head == nullptr)
        return nullptr;
    
    ListNode *tmp = head;
    int n = 0;
    while(tmp)
    {
        tmp = tmp->next;
        ++n;
    }
    k %= n;
    tmp = head;
    ListNode *kthNode = nullptr;
    n = 0;
    while(tmp)
    {
        if(n == k)
            kthNode = head;
        tmp = tmp->next;
        if(kthNode)
            kthNode = kthNode->next;
        ++n;
    }
    ListNode *l = reverse(head, kthNode), *r = reverse(kthNode);
    head->next = r;
    return reverse(l);
}
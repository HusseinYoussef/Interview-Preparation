#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode * reverse(ListNode*head, ListNode* end=nullptr)
{
    ListNode *pre = nullptr;
    while(head != end)
    {
        ListNode *tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return pre;
}

ListNode* rotateRight(ListNode* head, int k)
{
    if(head == nullptr)
        return nullptr;
    int n = 0;
    ListNode *tmp = head, *kthNode = nullptr;
    while(tmp)
    {
        tmp = tmp->next;
        n++;
    }
    k = k % n;
    tmp = head;
    n = 0;
    while(tmp)
    {
        if(n == k)
            kthNode = head;
        tmp = tmp->next;
        kthNode = kthNode ? kthNode->next : nullptr;
        ++n;
    }
    ListNode *l = reverse(head, kthNode), *r = reverse(kthNode);
    tmp = l;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = r;
    head = reverse(l);
    return head;
}
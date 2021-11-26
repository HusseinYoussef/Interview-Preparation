#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverse(ListNode* node)
{
    ListNode *pre = nullptr;
    while(node)
    {
        ListNode *next = node->next;
        node->next = pre;
        pre = node;
        node = next;
    }
    return pre;
}

bool isPalindrome(ListNode* head)
{
    int cnt = 0;
    ListNode *tmp = head;
    while(tmp)
    {
        cnt++;
        tmp = tmp->next;
    }
    tmp = head;
    for (int i = 0; i < cnt;++i)
    {
        if(i >= cnt/2)
        {
            tmp = reverse(tmp);
            break;
        }
        tmp = tmp->next;
    }
    bool ans = 1;
    ListNode *l = head;
    ListNode *r = tmp;
    for (int i = 0; i < cnt/2;++i)
    {
        if(l->val != r->val)
        {
            ans = 0;
            break;
        }
        l = l->next;
        r = r->next;
    }
    tmp = reverse(tmp);
    return ans;
}
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    cout << isPalindrome(head);
    return 0;
}
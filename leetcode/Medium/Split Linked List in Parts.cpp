#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

vector<ListNode*> splitListToParts(ListNode* head, int k)
{
    vector<ListNode *> ans(k, nullptr);
    ListNode *tmp = head;
    int n = 0;
    while(tmp)
        ++n, tmp = tmp->next;

    int sz = n / k, aux = n % k, cnt = 0, idx = 0;
    ListNode *pre = tmp = head;
    while(tmp)
    {
        ++cnt;
        if(cnt == sz + (aux>0))
        {
            ListNode *nxt = tmp->next;
            tmp->next = nullptr;
            aux--;
            ans[idx++] = pre;
            pre = tmp = nxt;
            cnt = 0;
        }
        else
            tmp = tmp->next;
    }
    return ans;
}
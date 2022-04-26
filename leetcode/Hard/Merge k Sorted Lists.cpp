#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

  
bool static cmp(ListNode* a, ListNode* b)
{
    return a->val > b->val;
}

ListNode* mergeKLists(vector<ListNode*>& arr)
{
    ListNode *dummy = new ListNode(0);
    ListNode *cur = dummy;
    int n = arr.size();

    priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> pq(cmp);
    for (int i = 0; i < n;++i)
    {
        if(arr[i] != nullptr)
        {
            pq.push(arr[i]);
        }
    }

    while(!pq.empty())
    {
        ListNode *node = pq.top();
        pq.pop();
        cur->next = node;
        cur = cur->next;
        if(node->next)
            pq.push(node->next);
    }
    return dummy->next;
}
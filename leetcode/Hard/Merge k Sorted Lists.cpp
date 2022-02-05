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

  
bool static cmp(ListNode *l, ListNode *r)
{
    return l->val > r->val;
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    int k = lists.size();
    priority_queue<ListNode *, vector<ListNode *>, function<bool(ListNode *, ListNode *)>> pq(cmp);

    for(int i =0;i<k;++i)
    {
        if(lists[i] != nullptr)
            pq.push(lists[i]);
    }

    if(pq.empty())
        return nullptr;

    ListNode *head = pq.top();
    while(!pq.empty())
    {
        ListNode *node = pq.top();
        pq.pop();
        if(node->next)
            pq.push(node->next);

        node->next = (pq.size())? pq.top():nullptr;
    }
    return head;
}

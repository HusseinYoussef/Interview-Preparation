using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
{
    ListNode* tail = list2;
    
    while (tail && tail->next)
    {
        tail = tail->next;
    }

    int idx = 1;
    ListNode* cur = list1;
    while (cur)
    {
        ListNode* tmp = cur->next;
        if (idx == a)
        {
            cur->next = list2;
        }
        if (idx == b + 1)
        {
            tail->next = cur->next;
            break;
        }

        ++idx;
        cur = tmp;
    }
    return list1;        
}

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

ListNode* reverse(ListNode* head)
{
    ListNode *pre = nullptr;
    while(head)
    {
        ListNode *tmp = head->next;
        head->next = pre;
        pre = head;
        head = tmp;
    }
    return pre;
}

void reorderList(ListNode* head)
{
    // O(1) Space
    ListNode *walker = head, *runner = head;
    while(runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
    }
    ListNode *l = head, *r = reverse(walker);
    while(l->next && r->next)
    {
        ListNode *tmp = l->next;
        l->next = r;
        l = tmp;
        tmp = r->next;
        r->next = l;
        r = tmp;
    }
    
    // O(N) Space
    // vector<ListNode *> vec;
    // ListNode *tmp = head;
    // while(tmp)
    // {
    //     vec.push_back(tmp);
    //     tmp = tmp->next;
    // }
    // int l = 0, r = vec.size() - 1;
    // while(l < r)
    // {
    //     vec[l++]->next = vec[r];
    //     if(l!= r)
    //         vec[r--]->next = vec[l];
    // }
    // vec[l]->next = nullptr;

}
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int n;
    ListNode* head;
    Solution(ListNode* head)
    {
        n = 0;
        this->head = head;
        ListNode* tmp = head;
        while(tmp)
        {
            ++n;
            tmp = tmp->next;
        }
    }
    
    int getRandom()
    {
        int idx = rand() % n + 1;
        ListNode* tmp = this->head;
        int i = 0, val = 0;
        while(tmp)
        {
            ++i;
            val = tmp->val;
            if(i == idx)
                break;
            tmp = tmp->next;

        }
        return val;
    }
};
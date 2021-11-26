#include <iostream>
#include <algorithm>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

void deleteNode(ListNode* node)
{
    ListNode *tmp = nullptr;
    while(node->next)
    {
        node->val = node->next->val;
        tmp = node;
        node = node->next;
    }
    tmp->next = nullptr;
}

int main()
{
    return 0;
}
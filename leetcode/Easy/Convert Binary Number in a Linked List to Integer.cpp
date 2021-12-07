#include <iostream>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int getDecimalValue(ListNode* head)
{
      int c = 1;
      ListNode* tmp = head;
      while(tmp)
      {
          c*=2;
          tmp = tmp->next;
      }
      int ans = 0;
      tmp = head;
      while(tmp)
      {
          c /= 2;
          ans += c * tmp->val;
          tmp = tmp->next;
      }
      return ans;
  }

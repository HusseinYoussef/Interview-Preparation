#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// reverse list
ListNode* rev(ListNode* head)
{
    ListNode *pre = nullptr, *tmp = head;
    while (tmp)
    {
        ListNode *nxt = tmp->next;
        tmp->next = pre;
        pre = tmp;
        tmp = nxt;
    }
    return pre;
}

vector<int> nextLargerNodes(ListNode* head)
{
    head = rev(head);
    stack<int> st;
    vector<int> ans;
    while(head)
    {
        while(st.size() && st.top() <= head->val)
            st.pop();

        ans.push_back((st.size()) ? st.top() : 0);
        st.push(head->val);
        head = head->next;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
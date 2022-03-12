#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head)
{
    unordered_map<int, Node *> mp;
    Node dummy = Node(0);
    Node *tmp = head, *cur = &dummy;
    int idx = 0;
    while(tmp)
    {
        cur->next = new Node(tmp->val);
        mp[idx] = cur->next;
        tmp->val = idx++;
        cur = cur->next;
        tmp = tmp->next;
    }
    tmp = head, cur = dummy.next;
    while(tmp)
    {
        if(tmp->random)
            cur->random = mp[tmp->random->val];
        cur = cur->next;
        tmp = tmp->next;
    }
    return dummy.next;
}
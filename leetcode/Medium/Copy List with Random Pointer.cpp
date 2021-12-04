#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head)
{
    Node *tmp = head;
    Node *cur = nullptr, *deepHead = nullptr;
    int i = 0;
    Node *arr[1005];
    while(tmp)
    {
        Node *node = new Node(tmp->val);
        if(cur == nullptr)
            deepHead = node;        
        else
            cur->next = node;

        cur = node;
        arr[i] = cur;
        tmp->val = i++;
        tmp = tmp->next;
    }
    tmp = head;
    cur = deepHead;
    while(tmp)
    {
        cur->random = tmp->random ? arr[tmp->random->val] : nullptr;
        tmp = tmp->next;
        cur = cur->next;
    }
    return deepHead;
}
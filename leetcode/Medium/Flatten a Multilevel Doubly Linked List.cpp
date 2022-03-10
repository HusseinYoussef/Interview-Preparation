#include <iostream>

using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

pair<Node*, Node*> rec(Node* head)
{
    Node *cur = head, *lst = head;
    while(cur)
    {
        lst = cur;
        if(cur->child)
        {
            pair<Node *, Node *> p = rec(cur->child);
            cur->child = nullptr;
            Node *tmp = cur->next;
            cur->next = p.first;
            p.first->prev = cur;
            p.second->next = tmp;
            if(tmp)
                tmp->prev = p.second;
            else
                lst = p.second;
            cur = tmp;
        }
        else
            cur = cur->next;
    }
    return {head, lst};
}

Node* flatten(Node* head)
{
    return rec(head).first;
}
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
       this->val = val;
       this->next = NULL;
    }
};

ListNode * insert(ListNode * node, int x)
{
    ListNode * newNode = new ListNode(x);
    if(node == nullptr)
        return newNode;

    ListNode * tmp = node;
    while(tmp->next->val < x && tmp->val <= tmp->next->val)
    {
        tmp = tmp->next;
        // Cycle
        if(tmp == node)
            break;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;
    return newNode;
}

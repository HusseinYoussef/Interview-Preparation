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

    ListNode * cur = node;
    while(true)
    {
        cur = cur->next;
        if(cur->val <= x && (cur->next->val > x || cur->next->val < cur->val))
            break;
        // Cycle
        if(cur == node)
            break;
    }
    newNode->next = cur->next;
    cur->next = newNode;
    return newNode;
}


/*
    Problem Statement


    You're given the head of a Singly Linked List whose nodes are in sorted order
    with respect to their values. Write a function that returns a modified version
    of the Linked List that doesn't contain any nodes with duplicate values. The
    Linked List should be modified in place (i.e., you shouldn't create a brand
    new list), and the modified Linked List should still have its nodes sorted
    with respect to their values.
*/

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList)
{
    LinkedList *tmp = linkedList, *pre = nullptr;
    while(tmp)
    {
        while(tmp->next && tmp->next->value == tmp->value)
            tmp = tmp->next;
        
        if(pre == nullptr)
            linkedList = tmp;
        else
            pre->next = tmp;
        pre = tmp;
        tmp = tmp->next;
    }
    return linkedList;
}

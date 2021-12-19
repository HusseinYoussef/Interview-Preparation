#include <iostream>
#include <queue>

using namespace std;

class Node
{
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

void dfs(Node* node, Node* next = nullptr)
{
    if(node == nullptr)
        return;
    node->next = next;
    dfs(node->left, node->right);
    dfs(node->right, next ? node->next->left : nullptr);
}

Node* connect(Node* root)
{
    dfs(root);
    return root;

    // BFS

    // queue<Node *> q;
    // q.push(root);
    // while(!q.empty())
    // {
    //     Node *pre = q.front();
    //     q.pop();
    //     if(pre == nullptr)
    //         continue;
    //     int p = q.size();
    //     q.push(pre->left);
    //     q.push(pre->right);
    //     for (int i = 0; i < p;++i)
    //     {
    //         Node *node = q.front();
    //         q.pop();
    //         if(node == nullptr)
    //             continue;
    //         pre = pre->next = node;
    //         q.push(pre->left);
    //         q.push(pre->right);
    //     }
    // }
    // return root;
}
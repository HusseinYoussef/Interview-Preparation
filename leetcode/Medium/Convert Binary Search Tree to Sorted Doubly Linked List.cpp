using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

TreeNode * head = nullptr, *last = nullptr, *pre = nullptr;
void inorder(TreeNode * node)
{
    if(node == nullptr)
        return;
    inorder(node->left);
    if(head == nullptr)
        head = node;
    last = node;
    if(pre != nullptr)
    {
        pre->right = node;
        node->left = pre;
    }
    pre = node;
    inorder(node->right);
}

TreeNode * treeToDoublyList(TreeNode * root)
{
    inorder(root);
    head->left = last;
    last->right = head;
    return head;
}


using namespace std;

// O(logN * logN)
int countNodes(TreeNode* root)
{
    if(root == nullptr)
        return 0;

    int lh = 1, rh = 1;
    TreeNode* l = root->left, *r = root->right;
    while(l)
    {
        ++lh;
        l = l->left;
    }
    while(r)
    {
        ++rh;
        r = r->right;
    }

    if(lh == rh)
        return pow(2, lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

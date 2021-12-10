#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int countChildren(vector<Node*> &children)
{
    int cnt =0;
    for(int i =0;i<children.size();++i)
    {
        if(children[i] != nullptr)
            ++cnt;
    }
    return cnt;
}

vector<int> postorder(Node* root)
{
    stack<Node*> st;
    vector<int>ans;
    if(root)
        st.push(root);
    while(!st.empty())
    {
        Node* node = st.top();
        if(countChildren(node->children) == 0)
        {
            st.pop();
            ans.push_back(node->val);
            continue;
        }
        for(int i = node->children.size()-1; i>=0; --i)
        {
            if(node->children[i] != nullptr)
                st.push(node->children[i]);
            node->children[i] = nullptr;
        }
    }
    return ans;
}

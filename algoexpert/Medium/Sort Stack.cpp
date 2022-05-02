#include <vector>
using namespace std;

void insert(vector<int> &stack, int data)
{
    if(stack.empty() || data >= stack.back())
    {
        stack.push_back(data);
        return;
    }
    
    int tmp = stack.back();
    stack.pop_back();
    insert(stack, data);
    stack.push_back(tmp);
}

void sort(vector<int> &stack)
{
    if(stack.size())
    {
        int tmp = stack.back();
        stack.pop_back();
        sort(stack);
        insert(stack, tmp);
    }
}

vector<int> sortStack(vector<int> &stack)
{
    sort(stack);
    return stack;
}

int main()
{
    vector<int> v = {-5, 2, -2, 4, 3, 1};
    sortStack(v);
}
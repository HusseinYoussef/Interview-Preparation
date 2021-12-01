#include <iostream>
#include <vector>

using namespace std;

vector<int> sumZero(int n)
{
    vector<int> ans;
    int s = n / 2;
    while(s)
    {
        ans.push_back(s);
        ans.push_back(s * -1);
        --s;
    }
    if(n & 1)
        ans.push_back(0);
    return ans;
}
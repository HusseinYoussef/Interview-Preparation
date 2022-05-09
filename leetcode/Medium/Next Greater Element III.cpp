#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int nextGreaterElement(int n)
{
    string num = to_string(n);
    for (int i = num.size() - 2; i >= 0;--i)
    {
        int mn = 10, idx = -1;
        for (int j = i + 1; j < num.size();++j)
        {
            if(num[j] > num[i] && num[j]-'0' < mn)
            {
                mn = num[j] - '0';
                idx = j;
            }
        }
        if(idx != -1)
        {
            swap(num[i], num[idx]);
            sort(num.begin() + i + 1, num.end());
            long tmp = stol(num);
            if(tmp > INT_MAX)
                return -1;
            return (int)tmp;
        }
    }
    return -1;
}
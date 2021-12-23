#include <iostream>
#include <vector>

using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k)
{
    int n = num.size();
    int carry = 0;
    for (int i = n - 1; i >= 0 || k;--i)
    {
        int d1 = 0, d2 = 0;
        if(i >= 0)
            d1 = num[i];
        if(k)
        {
            d2 = k % 10;
            k /= 10;
        }
        int sum = d1 + d2 + carry;
        carry = sum >= 10;
        sum %= 10;
        if(i >= 0)
            num[i] = sum;
        else
            num.insert(num.begin(), sum);
    }
    if(carry)
        num.insert(num.begin(), 1);
    return num;
}
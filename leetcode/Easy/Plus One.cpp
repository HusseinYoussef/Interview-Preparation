#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    bool carry = 1;
    for (int i = digits.size()-1; i >= 0 ;--i)
    {
        if(carry && digits[i] < 9)
        {
            digits[i]++;
            carry = 0;
            break;
        }
        else
        {
            digits[i] = 0;
            carry = 1;
        }
    }
    if(carry)
        digits.insert(digits.begin(), 1);
    return digits;
}

int main()
{
    vector<int> vec = {9, 9, 9};
    vector<int> res = plusOne(vec);
    for(int i :vec)
        cout << i;
    return 0;
}
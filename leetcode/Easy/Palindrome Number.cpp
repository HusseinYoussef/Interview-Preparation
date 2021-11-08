#include <iostream>
#include <vector>
#include<string>  

using namespace std;

bool isPalindrome(int x)
{
    if(x < 0)
        return false;

    string val = to_string(x);
    for (int i = 0, j = val.size() - 1; i <= j;i++,--j)
    {
        if(val[i] != val[j])
            return false;
    }
        return true;
}
int main()
{

    cout << isPalindrome(1000021);
    return 0;
}
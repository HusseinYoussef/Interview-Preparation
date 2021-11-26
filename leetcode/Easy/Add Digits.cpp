#include <iostream>

using namespace std;

int addDigits(int num)
{
    int ans = 0;
    while(num)
    {
        ans += num % 10;
        num /= 10;

        if(num == 0)
        {
            if(ans > 9)
            {
                num = ans;
                ans = 0;
            }
            else
                break;
        }
    }
    return ans;
}
int main()
{
    return 0;
}
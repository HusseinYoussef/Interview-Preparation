
using namespace std;

int brokenCalc(int startValue, int target)
{
    // goal to make target less than startValue ... Y less than X
    // if Y is even, Y = Y / 2, if Y is Odd, Y = Y / 2 + 1. Then when Y < X we keep adding 1's
    int ans = 0;
    while(target > startValue)
    {
        if(target & 1)
        {
            target = (target / 2) + 1;
            ans += 2;
        }
        else
        {
            target /= 2;
            ++ans;
        }
    }
    return ans + startValue - target;
}

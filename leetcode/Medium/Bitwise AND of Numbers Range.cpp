
using namespace std;

int rangeBitwiseAnd(int left, int right)
{
    int ans = 0;
    for(int i = 0;i<32;++i)
    {
        if((1<<i)&left && (1<<i)&right)
        {
            // if bit is '1' it should stay 1 for (1 << i) consecutive numbers
            if(right - left + 1 <= (1 << i))
                ans |= 1 << i;
        }
    }
    return ans;
}

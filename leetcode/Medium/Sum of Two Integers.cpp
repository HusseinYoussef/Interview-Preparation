
using namespace std;

int getSum(int a, int b)
{
    int ans = 0;
    int i = 0;
    bool carry = 0;
    for (; i < 32;++i)
    {
        if(carry ^ ((a & (1 << i)) != 0) ^ ((b & (1 << i)) != 0))
            ans |= (1 << i);
        carry = (carry && ((a & (1 << i)) != 0)) || (carry && ((b & (1 << i)) != 0)) || (((a & (1 << i)) != 0) && ((b & (1 << i)) != 0));
    }

    if(carry && i < 32)
        ans |= (1 << i);
    return ans;
}
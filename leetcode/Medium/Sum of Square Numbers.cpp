
using namespace std;

int sqroot(int num)
{
    long l = 0, r = num + 1, mid;
    while(r-l>1)
    {
        mid = l + (r - l) / 2;
        if(mid*mid > num)
            r = mid;
        else
            l = mid;
    }
    return l;
}

bool judgeSquareSum(int c)
{
    for (long a = 0; a * a <= c;++a)
    {
        int a2 = a * a;
        int b = sqroot(c - a2);
        // perfect square
        if(b*b == c-a2)
            return true;
    }
    return false;
}
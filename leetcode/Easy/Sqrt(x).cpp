
using namespace std;

int mySqrt(int x)
{
    long l = -1, r = (long)x+1, mid;
    while(r-l>1)
    {
        mid = l + (r-l)/2;
        if(mid*mid > x)
            r = mid;
        else
            l = mid;
    }
    return (int)l;
}
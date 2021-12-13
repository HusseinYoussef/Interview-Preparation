#include <iostream>
#include <vector>

using namespace std;

vector<int> selfDividingNumbers(int left, int right)
{
    vector<int>ans;
    for(int i =left;i<=right;++i)
    {
        int n = i;
        bool f = 1;
        while(n)
        {
            int d = n % 10;
            if(d == 0 || i % d != 0)
            {
                f = 0;
                break;
            }
            n /= 10;
        }
        if(f)
            ans.push_back(i);
    }
    return ans;
}

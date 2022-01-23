#include <vector>

using namespace std;

vector<int> sequentialDigits(int low, int high)
{
    int num; int tmp = 10;
    vector<int> ans;
    for(int i = 2;i<=9;++i)
    {
        num = 0;
        tmp *= 10;
        for(int j = 1;j<=i;++j)
        {
            num = num * 10 + j;
        }
        for(int k = 0; k<= 9-i;++k)
        {
            if(num >= low && num <= high)
                ans.push_back(num);
            num = (num * 10 + (i+k+1)) % tmp;
        }
    }
    return ans;
}

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int compress(vector<char>& chars)
{
    int n = chars.size();
    int idx = 0, cnt = 0;
    char lst = chars[0];
    for (int i = 0; i < n;++i)
    {
        // if idx == i then i-1 is overwritten we can't consider it
        if(i == 0 || (chars[i] == chars[i-1] && idx != i))
            cnt++;
        if(i + 1 >= n || chars[i] != chars[i+1])
        {
            chars[idx++] = chars[i];
            if(cnt > 1)
            {
                int dnum = log10(cnt) + 1;
                for (int k = idx + dnum - 1; k >= idx; --k)
                {
                    chars[k] = (cnt % 10) + '0';
                    cnt /= 10;
                }
                idx = idx + dnum;
            }
            cnt = 1;
        }
    }
    return idx;
}
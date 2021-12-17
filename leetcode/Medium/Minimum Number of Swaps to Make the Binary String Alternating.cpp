#include <iostream>

using namespace std;

int minSwaps(string s)
{
    int zeros = 0, ones = 0;
    for (int i = 0; i < s.size();++i)
        zeros += s[i] == '0', ones += s[i] == '1';
    
    if(abs(zeros - ones) > 1)
        return -1;

    int s1 = 0, s2 = 1;
    int cost1 = 0, cost2 = 0;  // number of flips
    for (int i = 0; i < s.size();++i)
    {
        if(s[i] - '0' != s1)
            ++cost1;
        if(s[i] - '0' != s2)
            ++cost2;
        s1 = !s1;
        s2 = !s2;
    }
    // 1 swap = 2 flips
    if(zeros == ones)
        return min(cost1, cost2) / 2;
    if(zeros > ones)
        return cost1 / 2;
    return cost2 / 2;
}
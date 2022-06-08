#include <iostream>

using namespace std;

bool checkString(string s)
{
    int n = s.size();
    
    int aidx = -1, bidx = n+1;
    for(int i = 0;i<n;++i)
    {
        if(s[i] == 'a')
            aidx = i;
        if(s[i] == 'b' && bidx == n+1)
            bidx = i;
    }
    return aidx <= bidx;
}
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool uniqueOccurrences(vector<int>& arr)
{
    int freq[2002];
    bool mp[2002];
    memset(freq,0,sizeof(freq));
    memset(mp,0,sizeof(mp));
    for(int i=0;i<arr.size();++i)
        freq[arr[i]+1000]++;
 
    for(int i =0;i<=2000;++i)
    {
        if(freq[i])
        {
            if(mp[freq[i]])
                return false;                
            mp[freq[i]] = 1;
        }
    }
    return true;        
}

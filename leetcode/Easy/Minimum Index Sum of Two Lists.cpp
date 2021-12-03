#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2)
{
    unordered_map<string, int> mp1;
    int mn = 10004;
    for (int i = 0; i < list1.size();++i)
        mp1[list1[i]] = i+1;
    for (int i = 0; i < list2.size();++i)
    {
        if(mp1[list2[i]])
        {
            mn = min(mn, mp1[list2[i]] - 1 + i);
        }
    }
    vector<string> ans;
    for (int i = 0; i < list2.size();++i)
    {
        if(mp1[list2[i]] && mp1[list2[i]] - 1 + i == mn)
        {
            ans.push_back(list2[i]);
        }
    }
    return ans;
}
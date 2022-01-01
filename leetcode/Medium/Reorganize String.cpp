#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

string reorganizeString(string s)
{
    int arr[26];
    memset(arr, 0, sizeof(arr));
    for(int i =0;i<s.size();++i)
    {
        arr[s[i]-'a']++;
        s[i] = '.';
    }
    priority_queue<pair<int, char>> pq;
    for(int i =0;i<26;++i)
    {
        if(arr[i])
            pq.push({arr[i], i+'a'});
    }
    int idx = 0;
    pair<int, char> pre = {0,'#'};
    while(!pq.empty())
    {
        pair<int, char> p = pq.top();
        pq.pop();
        s[idx++] = p.second;
        if(pre.first > 0)
            pq.push(pre);
        pre = {p.first-1, p.second};
    }
    if(idx != s.size())
        return "";
    return s;
}

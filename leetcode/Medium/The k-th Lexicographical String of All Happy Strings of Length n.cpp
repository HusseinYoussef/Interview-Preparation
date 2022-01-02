#include <iostream>
#include <vector>

using namespace std;

string res = "";
int cnt = 0;
char arr[3] = {'a', 'b', 'c'};
void rec(string s, int n, int k, char pre = '.')
{
    if(!res.empty())
        return;
    if(s.size() == n)
    {
        ++cnt;
        if(k == cnt)
            res = s;
        return;
    }
    for(int i =0;i<3;++i)
    {
        if(arr[i] != pre)
            rec(s+arr[i], n, k, arr[i]);
    }
}
string getHappyString(int n, int k)
{
    rec("", n, k);
    return res;
}

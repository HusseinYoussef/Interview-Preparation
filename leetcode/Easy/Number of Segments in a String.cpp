#include <iostream>
#include <vector>

using namespace std;

int countSegments(string s)
{
    bool see = 0;
    int cnt = 0;
    for (int i = 0; i < s.size();++i)
    {
        if(s[i] != ' ' && see == 0)
        {
            see = 1;
            cnt++;
        }
        if(s[i] == ' ')
        {
            see = 0;
        }
    }
    return cnt;
}
int main()
{
    return 0;
}
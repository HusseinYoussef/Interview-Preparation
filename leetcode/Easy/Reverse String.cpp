#include <iostream>
#include <vector>

using namespace std;

void reverseString(vector<char>& s)
{
    for (int i = 0; i < s.size() / 2;++i)
    {
        swap(s[i], s[s.size() - 1 - i]);
    }
}
int main()
{
    return 0;
}
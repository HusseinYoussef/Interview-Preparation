#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle)
{
    if(needle.size() == 0)
        return 0;

    return haystack.find(needle);
}
int main()
{
    cout << strStr("hh", "wd");
    return 0;
}
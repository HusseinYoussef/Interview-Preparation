#include <iostream>

using namespace std;

// Same as converting Decimal (sheet number) to binary (sheet column characters - base 26)
string convertToTitle(int columnNumber)
{
    string ans = "";
    while(columnNumber)
    {
        ans = char(((columnNumber-1) % 26) + 'A') + ans;
        columnNumber = (columnNumber - 1) / 26;
    }
    return ans;
}
int main()
{
    return 0;
}
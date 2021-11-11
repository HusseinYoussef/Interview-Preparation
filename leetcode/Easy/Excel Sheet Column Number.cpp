#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// Same as converting Binary to Decimal
int titleToNumber(string columnTitle)
{
    int ans = columnTitle[columnTitle.size() - 1] - 'A' + 1;
    int c = 1;
    for (int i = columnTitle.size() - 2; i >= 0; --i)
    {
        c *= 26;
        ans += c * (columnTitle[i] - 'A' + 1);
    }
    return ans;
}

int main()
{
    cout << titleToNumber("A");
    return 0;
}
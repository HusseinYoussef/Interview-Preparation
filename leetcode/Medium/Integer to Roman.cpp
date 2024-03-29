#include <iostream>
#include <vector>

using namespace std;

string intToRoman(int num)
{
    int arr[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string ch[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    string ans = "";
    while(num)
    {
        for (int i = 12; i >= 0;--i)
        {
            if(arr[i] <= num)
            {
                ans += ch[i];
                num -= arr[i];
                break;
            }
        }
    }
    return ans;
}
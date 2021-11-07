#include <iostream>
#include <map>

using namespace std;

int romanToInt(string s)
{
    int arr[50];
    arr['I' - '0'] = 1;
    arr['V' - '0'] = 5;
    arr['X' - '0'] = 10;
    arr['L' - '0'] = 50;
    arr['C' - '0'] = 100;
    arr['D' - '0'] = 500;
    arr['M' - '0'] = 1000;

    int ans = 0;
    for (int i = 0; i < s.size();)
    {
        if(i < s.size()-1)
        {
            if(s[i] == 'I' && s[i+1]=='V' || s[i] == 'I' && s[i+1]=='X' || s[i] == 'X' && s[i+1]=='L' || s[i] == 'X' && s[i+1]=='C' 
                || s[i] == 'C' && s[i+1]=='D' || s[i] == 'C' && s[i+1]=='M')
              {
                  ans += arr[s[i + 1] - '0'] - arr[s[i] - '0'];
                  i += 2;
                  continue;
              }
        }
        ans += arr[s[i] - '0'];
        i += 1;
    }
    return ans;
}

int main()
{
    cout << romanToInt("MCMXCIV");
    return 0;
}
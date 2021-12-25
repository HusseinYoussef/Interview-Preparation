#include <iostream>
#include <vector>

using namespace std;

int calculate(string s)
{
    // O(1) Space
    int n = s.size();
    int num = 0;
    int ans = 0, lstVal = 0; // last evaluated value
    char lst = '+';
    for (int i = 0; i < s.size();++i)
    {
        if(s[i] == ' ')
            continue;
        if(isdigit(s[i]))
        {
            num = num * 10 + (s[i] - '0');
        }
        if(isdigit(s[i]) && (i+1 == n || !isdigit(s[i+1])))
        {
            if(lst == '*')
                lstVal = lstVal * num;                
            else if(lst == '/')
                lstVal = lstVal / num;
            else
            {
                ans += lstVal;
                lstVal = (num * ((lst == '-') ? -1 : 1));
            }
            num = 0;
        }
        // operation
        if(!isdigit(s[i]))
        {
            lst = s[i];
        }
    }
    ans += lstVal;
    return ans;

    // O(N) Space using Stack

    // int n = s.size();
    // int num = 0;
    // vector<int> ops;
    // char lst = '#';
    // for (int i = 0; i < s.size();++i)
    // {
    //     if(s[i] == ' ')
    //         continue;
    //     if(isdigit(s[i]))
    //     {
    //         num = num * 10 + (s[i] - '0');
    //     }
    //     if(isdigit(s[i]) && (i+1 == n || !isdigit(s[i+1])))
    //     {
    //         if(ops.size() && (lst == '*' || lst == '/'))
    //         {
    //             int pre = ops[ops.size() - 1];
    //             ops.pop_back();
    //             if(lst == '*')
    //                 ops.push_back(pre * num);
    //             else
    //                 ops.push_back(pre / num);
    //         }
    //         else
    //             ops.push_back(num * ((lst == '-') ? -1 : 1));
    //         num = 0;
    //     }
    //     // operation
    //     if(!isdigit(s[i]))
    //     {
    //         lst = s[i];
    //     }
    // }
    // int ans = ops[0];
    // for (int i = 1; i < ops.size();++i)
    // {
    //     ans += ops[i];
    // }
    // return ans;
}
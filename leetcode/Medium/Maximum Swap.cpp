#include <iostream>

using namespace std;

int maximumSwap(int num)
{
    string s = to_string(num);
    for (int i = 0; i < s.size()-1;++i)
    {
        for (int j = i + 1; j < s.size();++j)
        {
            if(s[i] < s[j])
            {
                swap(s[i], s[j]);
                num = max(num, stoi(s));
                swap(s[i], s[j]);
            }
        }
    }
    return num;
}
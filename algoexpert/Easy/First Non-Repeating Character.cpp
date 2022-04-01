#include <iostream>
#include <vector>

using namespace std;

int firstNonRepeatingCharacter(string string)
{
    int n = string.size();
    vector<int> freq(26, 0);
    for (int i = 0; i < n;++i)
        ++freq[string[i] - 'a'];

    for (int i = 0; i < n;++i)
    {
        if(freq[string[i] - 'a'] == 1)
            return i;
    }
    return -1;
}
#include <iostream>
#include <vector>

using namespace std;

string restoreString(string s, vector<int>& indices)
{
    // since each indices[i] < 100 (7 bits), we can store the char(8 bits) and the index(7 bits) in the same binary representation (32-bit int)
    for (int i = 0; i < s.size();++i)
        indices[i] = (indices[i] << 8) | s[i];
    for (int i = 0; i < s.size();++i)
    {
        char c = ((1 << 8) - 1) & indices[i];
        s[indices[i] >> 8] = c;
    }
    return s;
}
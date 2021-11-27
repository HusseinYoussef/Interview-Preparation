#include <iostream>
#include <vector>

using namespace std;

int longestPalindrome(string s)
{
    vector<int> freq(60, 0);
    for (int i = 0; i < s.size();++i)
        freq[s[i] - 'A']++;

    int ans = 0;
    bool odd = 0;
    for (int i = 0; i < 60;++i)
    {
        odd |= freq[i] & 1;
        ans += freq[i] & 1 ? freq[i] - 1 : freq[i];
    }
    return ans + odd;
}

int main()
{
    cout << 'z' - 'A';
    return 0;
}

#include <iostream>

using namespace std;

bool detectCapitalUse(string word)
{
    int cnt=0;
    for(int i =0;i<word.size();++i)
    {
        cnt += isupper(word[i])>1;
    }
    if(cnt == word.size() || cnt == 0 || (cnt == 1 && isupper(word[0]))) 
        return true;

    return false;
}

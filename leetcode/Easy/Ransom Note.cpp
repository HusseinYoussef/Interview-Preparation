#include <iostream>
#include <vector>

using namespace std;

bool canConstruct(string ransomNote, string magazine)
{
    vector<int> vec(26);
    for (int i = 0; i < magazine.size();++i)
        vec[magazine[i] - 'a']++;
    
    for (int i = 0; i < ransomNote.size();++i)
    {
        if(!vec[ransomNote[i] - 'a'])
            return false;
        vec[ransomNote[i] - 'a']--;
    }
    return true;
}

int main()
{
    return 0;
}
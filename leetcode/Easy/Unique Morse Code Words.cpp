#include <iostream>
#include <unordered_map>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {

    string arr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.",
                    "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    unordered_map<string, bool> mp;
    int cnt = 0;
    for(int i =0;i<words.size();++i)
    {
        string ans = "";
        for(int j =0;j<words[i].size();++j)
        {
            ans += arr[words[i][j]-'a'];
        }
        if(!mp[ans])
            cnt++, mp[ans]= 1;
    }
    return cnt;
}

#include <iostream>
#include <vector>

using namespace std;

char nextGreatestLetter(vector<char>& letters, char target)
{
    // (l,r)
    // int l = -1, r = letters.size(), mid;
    // while (r - l > 1)
    // {
    //     mid = l + (r - l) / 2;
    //     if(letters[mid] > target)
    //         r = mid;
    //     else
    //         l = mid;
    // }
    // return letters[r%letters.size()];

    // [l,r]
    // int l = 0, r = letters.size()-1, mid;
    // while(l<=r)
    // {
    //     mid = l + (r - l) / 2;
    //     if(letters[mid] > target)
    //         r = mid-1;
    //     else
    //         l = mid+1;
    // }
    // return letters[l%letters.size()];

    // [l,r)
    int l = 0, r = letters.size(), mid;
    while(l<r)
    {
        mid = l + (r - l) / 2;
        if(letters[mid] > target)
            r = mid;
        else
            l = mid+1;
    }
    return letters[r%letters.size()];
}

int main()
{
    vector<char> vec = {'a', 'b', 'c'};
    char z = 'j';
    nextGreatestLetter(vec, z);
    return 0;
}


#include <vector>
using namespace std;

int binarySearch(vector<int> array, int target)
{
    int l = -1, r = array.size(), mid;
    while(r-l>1)
    {
        mid = l + (r - l) / 2;
        if(array[mid] >= target)
            r = mid;
        else
            l = mid;
    }
    if(array[r] == target)
        return r;
    return -1;
}

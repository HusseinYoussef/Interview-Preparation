#include <vector>
#include <algorithm>

using namespace std;

int numRescueBoats(vector<int>& people, int limit)
{
    int n = people.size();
    sort(people.begin(), people.end());
    int ans = 0, l = 0, r = n-1;
    while(l <= r)
    {
        if(people[l] + people[r] <= limit)
            ++l;
        --r;
        ++ans;
    }
    return ans;
}

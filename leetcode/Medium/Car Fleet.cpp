#include <vector>
#include <algorithm>

using namespace std;

int carFleet(int target, vector<int>& position, vector<int>& speed)
{
    int n = position.size();
    vector<pair<int, int>> vec;
    for(int i = 0;i<n;++i)
        vec.push_back({position[i], speed[i]});

    sort(vec.begin(), vec.end());

    // check if each car collide with the car in front of it
    // How to know? check if car can reach the target <= the car in front of it, then they must collide at some point
    int ans = 1, lst = n-1;
    for(int i = n-2;i>=0;--i)
    {
        double next = (target - vec[lst].first) * 1.0 / vec[lst].second;
        double cur = (target - vec[i].first) * 1.0 / vec[i].second;
        // cur <= next, then they will collide at some point and make 1 fleet
        if (cur > next) // no colistion
        {
            lst = i;
            ++ans;
        }
    }

    return ans;
}

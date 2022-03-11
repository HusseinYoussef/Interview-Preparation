#include <queue>
#include <map>
#include <set>

using namespace std;

// TLE but it passes if we get rid of the log n due to the map and set;
// BFS
bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
    queue<pair<int, int>> q;
    map<pair<int, int>, bool> mp;
    q.push({0, 0});
    mp[{0, 0}] = 1;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int c1 = p.first, c2 = p.second;
        if(c1 == targetCapacity || c2 == targetCapacity || c1+c2 == targetCapacity)
            return true;
        set<pair<int, int>> st;
        st.insert({jug1Capacity, c2});
        st.insert({c1, jug2Capacity});
        st.insert({0, c2});
        st.insert({c1, 0});
        st.insert({min(jug1Capacity, c1 + c2), (c1 + c2 <= jug1Capacity) ? 0 : c2 - (jug1Capacity - c1)});
        st.insert({(c1 + c2 <= jug2Capacity) ? 0 : c1 - (jug2Capacity - c2), min(c1 + c2, jug2Capacity)});

        for(auto &p : st)
        {
            if(mp[p])
                continue;
            q.push(p);
            mp[p] = 1;
        }
    }
    return false;
}

/*
    Problem Statement
    
    A tandem bicycle is a bicycle that's operated by two people: person A and
    person B. Both people pedal the bicycle, but the person that pedals faster
    dictates the speed of the bicycle. tandemSpeed = max(speedA, speedB)
    
    You're given two lists of positive integers: one that contains the speeds of
    riders wearing red shirts and one that contains the speeds of riders wearing
    blue shirts. Each rider is represented by a single positive integer, which is
    the speed that they pedal a tandem bicycle at. Both lists have the same
    length, meaning that there are as many red-shirt riders as there are
    blue-shirt riders. Your goal is to pair every rider wearing a red shirt with a
    rider wearing a blue shirt to operate a tandem bicycle.

    Write a function that returns the maximum possible total speed or the minimum
    possible total speed of all of the tandem bicycles being ridden based on an
    input parameter, fastest = True, your function should return the maximum possible total speed; otherwise it should
    return the minimum total speed.
*/

#include <vector>
#include <algorithm>

using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds, bool fastest)
{
    sort(redShirtSpeeds.begin(), redShirtSpeeds.end());
    sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end());
    
    int n = redShirtSpeeds.size();
    int l = 0, r = (fastest) ? n - 1 : 0;
    int ans = 0;
    for (int i = 0; i < n;++i)
    {
        ans += max(redShirtSpeeds[l], blueShirtSpeeds[r]);
        ++l;
        r += (fastest) ? -1 : 1;
    }
    return ans;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int heightChecker(vector<int>& heights)
{
    int cnt = 0;
    vector<int> vec = heights;
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size();++i)
        cnt += vec[i] != heights[i];
    return cnt;
}
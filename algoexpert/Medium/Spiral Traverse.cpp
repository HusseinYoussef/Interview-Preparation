
/*
    Problem Statement

    Write a function that takes in an n x m two-dimensional array (that can be
    square-shaped when n == m) and returns a one-dimensional array of all the
    array's elements in spiral order.

    Spiral order starts at the top left corner of the two-dimensional array, goes
    to the right, and proceeds in a spiral pattern all the way until every element
    has been visited.
*/

#include <vector>
using namespace std;

vector<int> spiralTraverse(vector<vector<int>> array)
{
    int n = array.size(), m = array[0].size();
    vector<int> ans;
    int d = 0;
    int rl = 0, rr = n - 1, cl = 0, cr = m - 1;
    while(rl <= rr && cl <= cr)
    {
        if(d == 0)
        {
            for (int i = cl; i <= cr;++i)
                ans.push_back(array[rl][i]);
            ++rl;
        }
        else if(d == 1)
        {
            for (int i = rl; i <= rr;++i)
                ans.push_back(array[i][cr]);
            --cr;
        }
        else if(d == 2)
        {
            for (int i = cr; i >= cl;--i)
                ans.push_back(array[rr][i]);
            --rr;
        }
        else
        {
            for (int i = rr; i >= rl;--i)
                ans.push_back(array[i][cl]);
            ++cl;
        }
        d = (d + 1) % 4;
    }
    return ans;
}


/*
Problem Statement


  You're given a non-empty array of positive integers representing the amounts
  of time that specific queries take to execute. Only one query can be executed
  at a time, but the queries can be executed in any order.
  
  Query waiting Time is defined as the amount of time that it must
  wait before its execution starts. In other words, if a query is executed
  second, then its waiting time is the duration of the first query; if a query
  is executed third, then its waiting time is the sum of the durations of the
  first two queries.
*/

#include <vector>
#include <algorithm>

using namespace std;

int minimumWaitingTime(vector<int> queries)
{
    sort(queries.begin(), queries.end());
    int n = queries.size(), cum_sum = 0;
    int ans = 0;
    for (int i = 0; i < n;++i)
    {
        ans += cum_sum;
        cum_sum += queries[i];
    }
    return ans;
}
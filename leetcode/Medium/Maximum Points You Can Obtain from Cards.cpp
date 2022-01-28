#include <vector>

using namespace std;

int maxScore(vector<int>& cardPoints, int k)
{
    int n = cardPoints.size(), sum = 0;
    for (int i = 0; i < n;++i)
        sum += cardPoints[i];

    if(n <= k)
        return sum;

    int winSum = 0, mx = 0, w = n-k;
    for (int i = 0; i < w;++i)
        winSum += cardPoints[i];

    mx = sum - winSum;
    for (int i = w; i < n;++i)
    {
        winSum += cardPoints[i] - cardPoints[i - w];
        mx = max(mx, sum - winSum);
    }
    return mx;
}
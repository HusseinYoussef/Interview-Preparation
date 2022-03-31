#include <vector>

using namespace std;

vector<double> sampleStats(vector<int>& count)
{
    // number of elements
    int cnt = 0;
    double mxfreq = 0, mode = 0, mn = -1, mx = -1;
    long sum = 0;
    for (int i = 0; i < count.size();++i)
    {
        if(count[i] > mxfreq)
        {
            mxfreq = count[i];
            mode = i;
        }
        if(count[i])
        {
            cnt += count[i];
            sum += (long)count[i] * i;
            if(mn == -1)
                mn = i;
            mx = i;
        }
    }

    int lower = cnt / 2 + (cnt & 1), upper = cnt / 2 + 1;
    int n = 0;
    int cand1 = -1, cand2 = -1;
    for (int i = 0; i < count.size();++i)
    {
        n += count[i];
        if(n >= lower && cand1 == -1)
            cand1 = i;
        if(n >= upper && cand2 == -1)
            cand2 = i;
    }
    vector<double> ans = {mn, mx, sum * 1.0 / cnt, (cnt & 1) ? cand1 : (cand1 + cand2) * 1.0 / 2, mode};
    return ans;
}
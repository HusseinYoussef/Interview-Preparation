#include <vector>

using namespace std;

int leastInterval(vector<char>& tasks, int n)
{
    vector<int> freq(26,0);
    for(int i = 0;i<tasks.size();++i)
        ++freq[tasks[i]-'A'];

    vector<int> time(26,0);
    bool f = 0;
    int ts = 0;
    int ans = 0;
    while(true)
    {
        int c = -1;
        int mx = -1;
        int mn = 1e7;
        f = 0;
        for(int i = 0;i<26;++i)
        {
            if(freq[i])
            {
                f = 1;
                if(ts >= time[i] && freq[i] > mx)
                {
                    mx = freq[i];
                    c = i;
                }
                mn = min(mn, time[i]);
            }
        }
        if(f == 0)
            break;
        if(c != -1)
        {
            --freq[c];
            time[c] = ts + n + 1;
            ++ans;
            ++ts;
        }
        else
        {
            ans += mn - ts;
            ts = mn;
        }
    }
    return ans;
}

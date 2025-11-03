using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids)
{
    int n = asteroids.size();

    vector<int> ans;

    for (int i = 0;i<n;++i)
    {
        if (asteroids[i] > 0)
        {
            ans.push_back(asteroids[i]);
        }
        else
        {
            bool asteroidAlive = 1;
            while(ans.size() && ans.back() > 0)
            {
                if (abs(asteroids[i]) == ans.back())
                {
                    asteroidAlive = 0;
                    ans.pop_back();
                    break;
                }
                else if (abs(asteroids[i]) > ans.back())
                {
                    ans.pop_back();
                }
                else
                {
                    asteroidAlive = 0;
                    break;
                }
            }

            if (asteroidAlive)
            {
                ans.push_back(asteroids[i]);
            }
        }
    }
    return ans;
}

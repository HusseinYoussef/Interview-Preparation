#include <vector>
#include <unordered_map>
#include <random>

using namespace std;

class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> mp;
    RandomizedSet()
    {}
    
    bool insert(int val)
    {
        if(mp.find(val) == mp.end())
        {
            nums.push_back(val);
            mp[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val)
    {
        if(mp.find(val) != mp.end())
        {
            int tmp = nums[nums.size() - 1];
            mp[tmp] = mp[val];
            swap(nums[nums.size() - 1], nums[mp[val]]);
            nums.pop_back();
            mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom()
    {
        return nums[rand() % nums.size()];
    }
};
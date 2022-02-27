#include <vector>

using namespace std;

void reverse(vector<int>& arr, int r)
{
    int l = 0;
    while(l < r)
        swap(arr[l++], arr[r--]);
}

vector<int> pancakeSort(vector<int>& arr)
{
    int n = arr.size();
    vector<int>ans;
    // start from the end, put each element to its right place (i) by moving it from (j) (where j != 0) -> 0 -> (i)
    for(int i = n-1;i>=0;--i)
    {
        int mx = 0, idx = 0;
        for(int j = 0;j<=i;++j)
        {
            if(arr[j] > mx)
                mx = arr[j], idx = j;
        }
        if(idx != 0)
            ans.push_back(idx+1);
        ans.push_back(i+1);
        reverse(arr, idx);
        reverse(arr, i);
    }
    return ans;
}

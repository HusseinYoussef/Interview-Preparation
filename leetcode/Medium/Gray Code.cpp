#include <vector>
#include <bitset>

using namespace std;

// must be reference &bits not bits
void rec(vector<int> &ans, bitset<32> &bits, int bit)
{
    if(bit < 0)
    {
        ans.push_back(bits.to_ulong());
        return;
    }
    rec(ans, bits, bit-1);
    bits.flip(bit);
    rec(ans, bits, bit-1);
}

vector<int> grayCode(int n)
{
    vector<int> ans;
    bitset<32> bits;
    rec(ans, bits, n-1);
    return ans;
}

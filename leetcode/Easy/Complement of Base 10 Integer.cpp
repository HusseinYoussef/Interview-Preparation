#include <iostream>

using namespace std;

int bitwiseComplement(int n)
{
      int ans = n == 0;
      int i = 0;
      while(n)
      {
          if(!(n & 1))
              ans |= 1 << i;
          n >>= 1;
          ++i;
      }
      return ans;
}

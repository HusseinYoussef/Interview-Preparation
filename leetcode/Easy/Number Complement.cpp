#include <iostream>

using namespace std;

int findComplement(int num)
{
      int ans = 0;
      int i = 0;
      while(num)
      {
          if(!(num & 1))
              ans |= 1 << i;
          num >>= 1;
          ++i;
      }
      return ans;
}

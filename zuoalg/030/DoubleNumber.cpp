#include <vector>
using namespace std;
class Solution {
public:
   vector<int> singleNumber(vector<int>& nums) {
      int eor1=0;
      for(int x:nums)
      {
          eor1^=x;
      }
      //brain kernighan算法
      //找到a^b最右边的1
      unsigned int rightOne=(unsigned int) eor1& (-(unsigned int)eor1);
      int a=0;
      for(int x:nums)
      {
          if(((unsigned int)x & rightOne)==0)
              a^=x;
      }
      return {a,a^eor1};
   }

};

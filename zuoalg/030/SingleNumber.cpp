#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int eorHas=0;
       for(int num : nums)
       {
           eorHas^=num;
       }
       return eorHas;
    }
};

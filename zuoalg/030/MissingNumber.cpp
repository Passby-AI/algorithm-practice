#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int eorAll=0;
        int eorHas=0;
        for(int i=0;i<nums.size();i++)
        {
            eorAll^=i;
            eorHas^=nums[i];
        }

        eorAll^=nums.size();
        return eorAll^eorHas;
        
    }
};

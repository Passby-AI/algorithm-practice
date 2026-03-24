#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        return find(nums,3);
    }
    int find(vector<int>& nums,int m)
    {
        int cnt[32]={0};
        for(int num:nums)
        {
            for(int i=0;i<32;i++)
                cnt[i]+=((unsigned int)num>>i)&1;
        }
        int ans=0;
        for(int i=0;i<32;i++)
        {
            if(cnt[i]%m!=0)
               ans |=1<<i; 
        }
        return ans;
    }
};

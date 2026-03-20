#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    //定义进制
        static const int BASE=10;

        
public:
    vector<int> sortArray(vector<int>& nums) {
         
        int n=nums.size();
        int minn=nums[0];
        for(int i=1;i<n;i++)
        {
            minn=min(nums[i],minn);
        }

        int maxn=0;
        for(int i=0;i<n;i++)
        {
            //变为非负数
            nums[i]-=minn;
            maxn=max(maxn,nums[i]);
            
        }

        radixSort(nums,n,bits(maxn));
         for(int i=0;i<n;i++)
        {
            //还原
            nums[i]+=minn;
        }
        return nums;


    }
    int bits(int number)
    {
        int ans=0;
        while(number>0)
        {
            ans++;
            number/=BASE;
        }
        return ans;
    }
    void radixSort(vector<int>& nums,int n,int bits)
    {
        int help[50001];
        
        for(int offset=1;bits>0;offset*=BASE,bits--)
        {
            int cnts[BASE]={0};
            for(int i=0;i<n;i++)
            {
                //提取数字某一位的技巧
                cnts[(nums[i]/offset)%BASE]++;
            }
            //处理成前缀次数累加的形式
            for(int i=1;i<BASE;i++)
            {
                cnts[i]=cnts[i]+cnts[i-1];
            }
            for(int i=n-1;i>=0;i--)
            {
                //前缀数量分区技巧
                //数字提取某一位技巧
                help[--cnts[(nums[i]/offset)%BASE]]=nums[i];
            }
             for(int i=0;i<n;i++)
            {
                nums[i]=help[i];
            }
        }
        

    }
};



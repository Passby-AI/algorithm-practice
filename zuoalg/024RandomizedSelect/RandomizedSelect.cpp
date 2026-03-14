#include <vector>
#include <random>
#include <ctime>

using namespace std;


class Solution {
private:
    int first,last;
    default_random_engine e{static_cast<unsigned int>(time(0))};
public:
    int findKthLargest(vector<int>& nums, int k) {
        return randomizedSelect(nums,nums.size()-k);
    }
    int randomizedSelect(vector<int>& nums, int i)
    {
        int ans=0;
        for(int l=0;int r=nums.size()-1;)
        {
            uniform_int_distribution<int> u(l,r);
            int randomIndex=u(e);
            partition(nums,l,r,nums[randomIndex]);

            if(i<first)
                r=first-1;
            else if(i>last)
                l=last+1;
            else
            {
                ans=nums[i];
                break;
            }
        }
        return ans;
        
    }
    void partition(vector<int> & nums,int l,int r,int x)
    {
        first=l;
        last=r;
        int i=l;
        int ans=0;
        while(i<=last)
        {
            if(nums[i]<x)
            {
                swap(nums,i,first);
                first++;
                i++;
            }
            if(nums[i]>x)
            {
                swap(nums,i,last);
                last--;
            }
            if(nums[i]==x)
            {

                i++;
            }
        }

    }
    void swap(vector<int>& nums,int a,int b)
    {
        int temp=nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
    }
};

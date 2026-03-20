#include <vector>
#include <numeric>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        priority_queue<double> queue;
        double sum=accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<nums.size();i++)
        {
            queue.push(nums[i]);
        }

        int ans=0;
        for(double minus=0,cur; minus<sum/2;ans++,minus+=cur)
        {
            cur=queue.top()/2;
            queue.pop();
            queue.push(cur);

        }
        return ans;

    }
};

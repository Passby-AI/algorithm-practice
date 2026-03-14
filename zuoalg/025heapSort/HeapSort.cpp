#include <vector>
using namespace std;
class Heap
{
public:
    void heapSort1(vector<int> & nums)
    {
        //大根堆：任何一个子树的最大值都在根处
        //这里是自上而下的插入法
        int size=nums.size();
        for(int i=0;i<size;i++)
        {
            heapInsert(nums,i);
        }
        while(size>1)
        {
            swap(nums,0,--size);
            heapify(nums,0,size);
        }

    }
    void heapSort2(vector<int>& nums)
    {
        int n=nums.size();
        for(int i=n-1;i>=0;i--)
        {
            heapify(nums,i,n);
        }
        int size=n;
        while(size>1)
        {
            swap(nums,0,--size);
            heapify(nums,0,size);
        }

    }
    void heapInsert(vector<int>& nums,int i)
    {
        //i位置的数，向上调整大根
        //arr[i]=x,x是新来的！往上看，直到比父亲大 
        while(nums[i]>nums[(i-1)/2])
        {
            swap(nums,i,(i-1)/2);
            i=(i-1)/2;

        }
        

    }
    void heapify(vector<int>& nums,int i,int size)
    {
        //i位置的数，变小了，又想维持大堆根结构
        //向下调整大根堆
        //i的数变小的时候
        //选出最强的孩子
       int l=i*2+1;
       while(l<size)
       {
            int best = l+1<size && nums[l]<nums[l+1] ? l+1: l;
            best=nums[best]>nums[i] ? best: i;
            if(best==i)
            {
                break;
            }
            swap(nums,i,best);
            i=best;
            l=i*2+1;

        }
    }
    vector<int> sortArray(vector<int>& nums)
    {
        if(nums.size()>1)
        {
            heapSort2(nums);
        }
        return nums;

    }
    void swap(vector<int>& nums,int i,int j)
    {
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
};

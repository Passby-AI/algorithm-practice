//二分搜索
//1 利用二分搜索查找是否存在一个数（前提有序）
//2 查找找到大于某一值的最小的数，以及小于某一个值的最大的数（前提都有序）
//3 利用二分法查一个相邻数不相同的数组的一个峰值，不需要有序，判断趋势
//二分法条件扩展-> 找到一个区间必然满足这个条件/必然不满足这个条件

#include <iostream>
#include <ctime>
#include <random>

using namespace std;

//查找是否存在一个数字

bool exist(int*,int,int);
int findLeft(int*,int,int);
int findRight(int*, int,int);
int findPeakElement(int*,int,int);


int main()
{
    int N=100;
    int V=1000;
    int testTime=50000;
    cout<<"test starting"<<endl;
    //default_random_engine e;
   // uniform_int_distribution<int> u(1,V);
    //e.seed(time(0));
    //int arr[N];
    //for(int i=0;i<N;i++)
   // {
    //    arr[i]=u(e);
    //}
    int arr[8]={1,2,4,6,7,9,11,19};
    if(exist(arr,11,8))
        cout<<"exist"<<endl;
    else cout<<"Nope"<<endl;

    int ans=findLeft(arr,10,8);
    cout<<ans<<endl;
    return 0;




}


bool exist(int*arr,int num,int len)
{
    if(arr==nullptr||len==0) return false;
    int l=0;
    int r=len-1;
    while(l<=r)
    {
        int m=(l+r)/2;
        //or m=l+((l-r)>>1);
        if(arr[m]==num)
            return true;
        else if(arr[m]>num)  
        {
            r=m-1;
        }
        else    l=m+1;
    }
    return false;
}


//保证arr有序，才可以用这种方法
//有序数组中找>=num的最左位置

int findLeft(int *arr,int num,int len)
{
    int l=0;
    int r=len-1;
    int m=0;
    int ans=-1;
    while(l<=r)
    {
        m=(l+r)/2;
        if(arr[m]==num) return m;
        else if(arr[m]>num)
        {
            ans=m;
            r=m-1;
        }
        else 
            l=m+1;
    }
    return ans;
}


//同理，找<=num的最右位置

int findRight(int* arr,int num, int len)
{
    int l=0;
    int r=len-1;
    int m=0;
    int ans=-1;
    while(l<=r)
    {
        m=l+((l-r)>>1);
        if(arr[m]==num) return m;
        else if(arr[m]<num)
        {
            ans=m;
            l=m+1;
        }
        else
            r=m-1;
    }
    return ans;
}

//如果是找到<=num的最左位置
//直接比较arr[0]的值就好了，即数组的最小值
//if arr[0]<=num; 最左位置就是0
//如果是大于，那么就返回-1，毕竟其他的都大于等于arr[0]，更不符合条件

// 峰值元素是指其值严格大于左右相邻值的元素
// 给你一个整数数组 nums，已知任何两个相邻的值都不相等
// 找到峰值元素并返回其索引
// 数组可能包含多个峰值，在这种情况下，返回 任何一个峰值 所在位置即可。
// 你可以假设 nums[-1] = nums[n] = 无穷小
// 你必须实现时间复杂度为 O(log n) 的算法来解决此问题。

int findPeakElement(int* arr,int len)
{
    if(len<=1)  return 0;
    if(arr[0]>arr[1])   return 0;
    if(arr[len-1]>arr[len-2])   return len-1;
    int l=1;
    int r=len-2;
    int m=0;
    int ans=-1;
    while(l<=r)
    {
        m=(l+r)/2;
        if(arr[m-1]>arr[m])
           r=m-1;
        if(arr[m+1]>arr[m])
            l=m+1;
        else
        {
            ans=m;
            break;
        }
    }
    return ans;
}

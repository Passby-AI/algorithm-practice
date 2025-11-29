//对数器:验证最优算法的正确性
//比如：你有一个保证结果正确的暴力算法
//和一个想要验证是否正确的最优算法
//可以在一定数量的测试测试次数下，用大数据比对答案
//如果发现有错误，再带上小数据比对，用Print和手动调试的方法

#include <cstring>
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int* randomArray(int,int);
int* copyArray(int*,int);
bool sameArray(int*,int*,int);
void swap(int*,int,int);
void SelectSort(int*,int);
void BubbleSort(int*,int);
void InsertionSort(int*,int);
void printArray(int*,int);



int main()
{
    //随机数组的最大长度
    int N=200;
    //随机数组每个值，在1~v等概率随机
    int V=1000;

    //testTimes:测试次数
    int testTimes=50000;
    for(int i=0;i<testTimes;i++)
    {
        //随机得到一个长度，长度在[0~N-1];
        default_random_engine e;
        uniform_int_distribution<int> u(0,N-1);
        int n=u(e);
        //得到随机数组
        int *arr=randomArray(n, V);
        int *arr1=new int [n];
        memcpy(arr1, arr, n*sizeof(int));
        int *arr2=copyArray(arr, n);
        int *arr3=copyArray(arr, n);
        SelectSort(arr1,n);
        BubbleSort(arr2, n);
        InsertionSort(arr3,n);
        if(!sameArray(arr1, arr2, n)||!sameArray(arr1,arr3, n))
            cerr<<"error"<<endl;

    }
    cout<<"Done"<<endl;
}


int* randomArray(int n,int v)
{
    default_random_engine e;
    uniform_int_distribution<int> u(1,v);
    e.seed(time(0));
    int * arr=new int[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=u(e);
    }
    return arr;
}

//为了验证

int* copyArray(int * arr,int n)
{
    int *ans=new int[n];
    for(int i=0;i<n;i++)
        ans[i]=arr[i];
    return ans;
}

//为了验证

bool sameArray(int* arr1,int *arr2,int len)
{
    for(int i=0;i<len;i++)
    {
        if(arr1[i]!=arr2[i])
            return false;
    }
    return true;

}

//下面用选择排序的例子试一试

void swap(int *arr,int i,int j)
{
    if(arr[i]==arr[j])  return;
   arr[i]=arr[i]^arr[j]; //7^7=0 0^7=7 7^0=7
   arr[j]=arr[i]^arr[j];
   arr[i]=arr[i]^arr[j];
   //异或交换无法直接处理相同值交换的情况

//选择排序
}

void SelectSort(int *arr,int length)
{
    if(arr==nullptr||length<2)
        return;
    for(int minIndex,i=0;i<length-1;i++)
    {
        minIndex=i;
        for(int j=i+1;j<length;j++)
        {
            if(arr[j]<arr[minIndex])
            {
                minIndex=j;
            }

        }
        swap(arr,i,minIndex);
    }
}

//冒泡排序

void BubbleSort(int *arr,int length)
{
    if(arr==nullptr||length<2)    return;
    //i--这样更符合冒泡排序从大开始排特点
    for(int i=length-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[j]>arr[j+1])
                swap(arr,j,j+1);

        }

    }
}

//插入排序
void InsertionSort(int *arr,int length)
{
    if(arr==nullptr ||length<2)    return;
    for(int i=1;i<length;i++)
    {
        for(int j=i-1;j>=0&&arr[j]>arr[j+1];j--)
            swap(arr,j,j+1);
        
    }
}

void printArray(int *arr,int length)
{
    for(int i=0;i<length;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


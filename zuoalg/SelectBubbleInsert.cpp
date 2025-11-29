#include <iostream>


using namespace std;

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

int main(int argc,const char *argv[])
{
    int arr[8]={17,9,8,6,7,45,7,90};
    int arr1[8];
    int arr2[8];
    int arr3[8];
    
    memcpy(arr1,arr,8*sizeof(int));
    memcpy(arr2,arr,8*sizeof(int));
    memcpy(arr3,arr,8*sizeof(int));
    SelectSort(arr1,8);
    BubbleSort(arr2,8);
    InsertionSort(arr3,8);
    printArray(arr, 8);
    printArray(arr1,8);
    printArray(arr2,8);
    printArray(arr3, 8);

}

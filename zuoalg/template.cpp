#include <iostream>
#include <ctime>
#include <random>

using namespace std;

//usege

template<class T>
int length(T &arr)
{
    return sizeof(arr)/sizeof(arr[0]);
}

template<class T>
void print(T &arr)
{
    for(int i=0;i<length(arr);i++)
    {
        cout<<arr[i]<<" ";
    }
}

template<class T>
void swap(T *arr, int m,int n)
{
    T tem=arr[m];
    arr[m]=arr[n];
    arr[n]=tem;
}



#include <iostream>
#include <ctime>
#include <random>

using namespace std;

void partition(int ,int, int, int*);
void swap(int,int,int*);
default_random_engine e(time(0));
int first,last;

void quickSort(int l, int r,int* arr)
{
    if(l>=r)
        return;
    uniform_int_distribution<int> u(l,r);
    int randomIndex = u(e);
    int x=arr[randomIndex];
    partition(l,r,x,arr);
    int left=first;
    int right=last;
        quickSort(l,left-1,arr);
        quickSort(right+1,r,arr);

}

void partition(int l,int r ,int x,int* arr )
{
    first=l;
    last=r;
    int i=l;
    while(i<=last)
    {
        if(arr[i]==x)
        {
            i++;
        }
        else if(arr[i]<x)
        {
            swap(first++,i++,arr);
        }
        else
        {
            swap(i,last--,arr);
        }
    }
}

void swap(int a,int b ,int* arr)
{
    int temp=arr[a];
    arr[a]=arr[b];
    arr[b]=temp;
}

// 经典随机快速排序（不推荐）
#include <iostream>
#include <ctime>  //获取时间作为随机数种子
#include <random> //c++11引入的随机数库
#include <utility>

using namespace std;
void quickSort(int, int, int *);
int partition(int, int, int, int *);
void swap(int, int, int *);

default_random_engine e(time(0));
//uniform_int_distribution<int> u(0, 1);是返回的是整数 0 或者 1

int main()
{
    int n;
    /*cin >> n;
    int arr[n];
    */
    if(!(cin>>n))   return 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(0, n - 1, arr);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void quickSort(int l, int r, int *arr)
{
    if (l >= r)
        return;

    //    int x = int(l + (r - l + 1) * u(e));
    uniform_int_distribution<int> u(l,r);
    int randomIndex=u(e);
    int x=arr[randomIndex];
    int m = partition(l, r, x, arr);
    quickSort(l, m - 1, arr);
    quickSort(m + 1, r, arr);
}

int partition(int l, int r, int m, int *arr)
{
    int a = l, xi = 0;
    for (int i = l; i <= r; i++)
    {
        if (arr[i] <= m)
        {
            swap(a, i, arr);
            if (arr[a] == m)
                xi = a;
            a++;
        }
    }
    swap(xi, a - 1, arr);
    return a - 1;
}

void swap(int a, int b, int *arr)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

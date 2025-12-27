#include <iostream>
#define MAXSIZE 500

using namespace std;

void numConvert(int n,int r)
{
    int stack[MAXSIZE];
    int top=-1;//初始化栈，没有元素时指向-1
    while(n>0)
    {
        stack[++top]=n%r;
        n=n/r;
    }
    while(top!=-1)  cout<<stack[top--];
}

int main()
{

    int n,r;
    cin>>n>>r;
    numConvert(n, r);
    return 0;
}


#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a[510]={0};
    int r,n,s=0;
    cin>>n>>r;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(i>=r+1)
            a[i]=a[i]+a[i-r];
        s+=a[i];
    }
    cout<<s<<endl;
}

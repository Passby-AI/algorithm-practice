#include<iostream>

using namespace std;

const int MAXN=100001;
int arr[MAXN];
int help[MAXN];

int merge(int l,int m, int r)
{
    int ans=0;
    for(int i=l,j=m+1;i<=m;i++)
    {
        while(j<=r && arr[i]>2*arr[j])
        {
            j++;
        }
        ans+=j-m-1;
    }
    int i=l;
    int a=l;
    int b=m+1;
    while(arr[a]<=m&&b<=r)
    {
        help[i++]=(arr[a]<=arr[b]? arr[a++]:arr[b++]);
    }
    while(a<=m)
        help[i++]=arr[a++];
    while(b<=r)
        help[i++]=arr[b++];
    for(i=l;i<=r;i++)
        arr[i]=help[i];
    return ans;
}

int counts(int l,int r)
{
    if(l==r)
        return 0;
    int m=(l+r)>>1;
    return counts(l, m)+counts(m+1, r)+merge(l,m,r);
}

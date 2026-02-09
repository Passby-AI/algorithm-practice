#include <iostream>
using namespace std;
const int MAXN=100001;
int n;
int arr[MAXN];
int help[MAXN];
long long merge(int,int,int);
long long smallSum(int,int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<smallSum(0,n-1)<<'\n';
    }
    return 0;
}
// 64 位输出请用 printf("%lld")
long long smallSum(int l, int r)
{
    if(l==r)
    {
        return 0;
    }
    int m=(l+r)/2;
    return smallSum(l,m)+smallSum(m+1, r) +merge(l,m,r);
}


long long merge(int l,int m, int r)
  {
      long long ans=0;
      for(int j=m+1,i=l,sum=0;j<=r;j++)
      {
          while(i<=m&& arr[i]<=arr[j])
          {
              sum+=arr[i++];
          }
          ans+=sum;
      }
      int i =l;
      int a=l;
      int b=m+1;
      
      while(a<=m&&b<=r)
      {
          help[i++]=(arr[a]<=arr[b]? arr[a++]:arr[b++]);
      }
      while(a<=m)
      {
          help[i++]=arr[a++];
      }
      while(b<=r)
      {
          help[i++]=arr[b++];
      }
      for(i=l;i<=r;i++)
        arr[i]=help[i];
      return ans;
  }

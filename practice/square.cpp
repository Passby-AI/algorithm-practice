#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n,m;
    cin>>n>>m;
    int k=min(n,m);

    long long sum=n*(n+1)/2*m*(m+1)/2;
    long long square=0;
    for(int i=0;i<k;i++)
    {
        square+=(m-i)*(n-i);

    }
    long long rectangle=sum-square;
    cout<<"rectangle: "<<rectangle<<endl;
    cout<<"square "<<square<<endl;
    cout<<"sum:"<<sum<<endl;



}

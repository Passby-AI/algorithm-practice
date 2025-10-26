#include <iostream>


using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[10][10]={0};
    for(int i =0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int p=i;p<n;p++)
            {
                for(int q=j;q<m;q++)
                {
                    if(p-i==q-j)
                    {
                        continue;
                    }
                    a[i][j]++;
                    a[n][m]++;
                }

            }
        }
    }
    cout<<a[n][m]<<endl;
}

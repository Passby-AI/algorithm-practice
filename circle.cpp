#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    string job[n];

    int dir[n];
    for(int i=0;i<n;i++)
    {
        cin>>dir[i];
        cin>>job[i];
    }
    int d,s;
    string * cur1=&job[0];
    int * cur2=&dir[0];
    
    for(int i=0;i<m;i++)
    {
        cin>>d>>s;
        
        if(*cur2==1)
            d= (d==0)? 1:0;
        
        for(int j=0;j<s;j++)
        {
            if(d==1)
            {
                if(*cur1==job[n-1])
                {
                    cur1=&job[0];
                    cur2=&dir[0];
                }
                else
                {
                    cur1++;
                    cur2++;
                }
            }
            if(d==0)
            {
                if(*cur1==job[0])
                {
                    cur1=&job[n-1];
                    cur2=&dir[n-1];
                }
                else
                {
                    cur1--;
                    cur2--;
                }
            }
        }
    }
    cout<<*cur1;
    return 0;
}

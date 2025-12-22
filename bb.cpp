#include <iostream>

using namespace std;
int main()
{
    int n=0,na=0,nb=0;
    scanf("%d",&n);
    scanf("%d",&na);
    scanf("%d",&nb);
    int a[na];
    int b[nb];
    for(int i =0;i<na;i++)
            scanf("%d",&a[i]);
    for(int i=0;i<nb;i++)
            scanf("%d",&b[i]);
    int ra,rb;
    int suma=0,sumb=0;
    for(int i=0;i<n;i++)
    {
        if(i<=na-1)
            ra=a[i];
        else
            ra=a[i%na];
        if(i<=nb-1)
            rb=b[i];
        else
            rb=b[i%nb];
        if(ra==rb)
            continue;
        if(ra==0)
        {
            if(rb==2||rb==3)
                suma++;
            else
                sumb++;
        }
        if(ra==1)
        {
            if(rb==0||rb==3)
                suma++;
            else
                sumb++;
        }
        if(ra==2)
        {
            if(rb==1||rb==4)
                suma++;
            else
                sumb++;
        }
        if(ra==3)
        {
            if(rb==2||rb==4)
                suma++;

            else sumb++;
        }
        
        
        if(ra==4)
        {
            if(rb==2||rb ==3)
                suma++;
            else
                sumb++;
        }
    }
    cout<<suma<<" "<<sumb;
    return 0;
        
}

#include<iostream>
#include<string>
 using namespace std;

int main()
{
    int n;
    cin>>n;
    string result;
    int a[n+1];
    string c[n+1];
    for(int i=n;i>=0;i--)
    {
        cin>>a[i];
       if(a[i]==0) continue; 
            
            if(a[i]>0)
            {
                if(a[i]==1)
                    c[i]="+";
                else
                    c[i]="+"+to_string(a[i]);
            }
            else
            {
                if(a[i]==-1)
                    c[i]="-";
                else
                    c[i]=to_string(a[i]);
            }
        if(i==n)
        {
            if(a[i]>0)
                c[i].erase(0,1);

        }
        if(i==0)
        {
            if(a[i]==1|| a[i]==-1)
                c[i]+='1';
        }

    }
    for(int i=n;i>=0;i--)
    {
        if(a[i]==0)
            continue;
        
        if(i==1)
            result+=c[i]+"x";
        else if(i==0)
            result+=c[i];
        else
            result+=c[i]+"x^"+to_string(i);
    }
    cout<<result;
    return 0;    
}

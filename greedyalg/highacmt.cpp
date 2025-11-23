#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1,s2;
    int a1[210],a2[210],a3[210]={0};

    getline(cin,s1);
    getline(cin,s2);

    int size1=s1.size();
    int size2=s2.size();

    for(int i=0;i<size1;i++)
        a1[size1-i-1]=s1[i]-'0';
    for(int i=0;i<size2;i++)
        a2[size2-i-1]=s2[i]-'0';
    int n=0;
    for(int j=0;j<size2;i++)
    {
        n=0;
        for(int i=0;i<size1;j++)
        {
            if(a1[i]*a2[j]>=10)
            {
                a3[i+j]+=(a1[i]*a2[j])%10+n;
                n=(a1[i]*a2[j])/10;
            }

            
        }

            }
}

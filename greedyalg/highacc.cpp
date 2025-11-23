#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a1[210],a2[210],a3[210]={0};
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(int i=0;i<s1.size();i++)
        a1[s1.size()-i-1]=s1[i]-'0';
    for (int i=0;i<s2.size();i++)
        a2[s2.size()-i-1]=s2[i]-'0';
    int len=s1.size();
    if(s2.size()>len)
        len=s2.size();
    for(int i=0;i<len;i++)
    {
        a3[i]+=a1[i]+a2[i];
        if(a3[i]>=10)
        {
            a3[i]=a3[i]%10;
            a3[i+1]+=1;
        }

    }
    if(a3[len]!=0)
        len+=1;
    for(int i=len-1;i>=0;i--)
        cout<<a3[i];
}

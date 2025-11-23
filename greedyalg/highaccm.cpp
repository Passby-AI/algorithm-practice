#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string s1,s2;
    int a1[210],a2[210],a3[210]={0};
    getline(cin,s1);
    getline(cin,s2);
    
    char flag='+';
    int size1=s1.size();
    int size2=s2.size();
    if(size1<size2 || size1==size2 &&s1<s2)
    {
        swap(s1,s2);
        flag='-';
    }
    for(int i=0;i<size1;i++)
        a1[size1-i-1]=s1[i]-'0';
    for(int i=0;i<size2;i++)
        a2[size2-i-1]=s2[i]-'0';
    for(int i=0;i<size1;i++)
    {
        if(a1[i]>=a2[i])
            a3[i]=a1[i]-a2[i];
        else
        {
            a1[i+1]--;
            a3[i]=10+a1[i]-a2[i];
        }

    }
    int index=size1-1;
    if(a3[index]==0)
        index--;
    if(flag=='-')
        cout<<'-';
    for(int i=index;i>=0;i--)
        cout<<a3[i];
}

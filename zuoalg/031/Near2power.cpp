#include <iostream>
using namespace std;

int near2power(int n)
{
    if(n<=0)
        return 1;
    n--;

    n|= (unsigned int) n>>1;
    n|= (unsigned int) n>>2;
    n|= (unsigned int) n>>4;
    n|= (unsigned int) n>>8;
    n|= (unsigned int) n>>16;
    return n+1;
}

int main()
{
    int n;
    cin>>n;
    cout<<near2power(n)<<"\n";
    return 0;
}

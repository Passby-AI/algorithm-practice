#include <iostream>
using namespace std;
//提取二进制最右侧的1
//判断一个数是不是2的幂

bool isPowerOfTwo(int n)
{
    return n>0 && n==((unsigned int)n&(-(unsigned int)n));
}
int main()
{
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n)<<"\n";
    return 0;
}

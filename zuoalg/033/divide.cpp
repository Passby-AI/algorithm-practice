#include <iostream>
#include <climits>
#include <iostream>
#include <climits>

class Solution {
private:
    int MIN=INT_MIN;
    int MAX=INT_MAX;
public:
    int divide(int dividend, int divisor) {
       //有以下几种情况
       //x,y都是最小值 -> 1
       //y最小值，x不是 ->0
        //x最小，y不是 ->x加上y绝对值再运算
        //x,y都正常
        if(divisor==0)
            return MAX;
        if(dividend==MIN && divisor ==MIN)
            return 1;
        if(dividend!=MIN && divisor!= MIN)
            return div(dividend,divisor);
        if(divisor==MIN)
            return 0;
        if(divisor==neg(1))
            return MAX;
        dividend=add(dividend,divisor>0? divisor:neg(divisor));
        int offset=divisor>0? neg(1): 1;
        int ans=div(dividend,divisor);
        return add(ans,offset);
    }
int add(int x,int y)
{
    int sum=x;
    while(y!=0)
    {
       sum=x^y;
       int carry=(unsigned int)(x&y)<<1;
       y=carry;
       x=sum;
    }
    return sum;
}
int neg(int x)
{
    return add(~x,1);
}

int minus(int x,int y)
{
    return add(x,neg(y));
}

    int multiple(int x,int y)
{
    int ans=0;
    while(y!=0)
    {
        if((y&1)!=0)
        {
            ans=add(ans,x);
        }
        x<<1;
        y>>1;

    }
    return ans;
}
    int div(int x,int y)
{
    int a=x<0? neg(x):x;
    int b=y<0? neg(y):y;
    int ans=0;
    //保证a,b都不使最小整数
    for(int i=31;i>=0;i=minus(i,1))
    {
        if((a>>i)>=b)
        {
            a=minus(a, b<<i);
            ans|=(1<<i);

        }
    }
    return x<0 ^ y<0 ? neg(ans):ans;

}
};



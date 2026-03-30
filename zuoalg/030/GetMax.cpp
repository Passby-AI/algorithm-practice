#include<iostream>

using namespace std;

//反转
 int flip(int n)
{
    return n^1;
}

//非负数返回1,复数返回0

int sign(int n)
{
    /*
        - `>>` 对无符号数是逻辑右移，对有符号数是算术右移。
        - `<<` 左移时两者无区别，都是补0。
     * */
   //转化为无符号类型 
    return flip((unsigned int)n >>31);

}


int getMax1(int a,int b)
{
    //有溢出风险
    int c=a-b;
    int returnA=sign(c);
    int returnB=flip(returnA);
    return a*returnA + b* returnB;
}

int getMax2(int a,int b)
{
    //c依旧有一溢出风险
    int c=a-b;
    //判判断a,b符号
    int sa=sign(a);
    int sb=sign(b);
    int sc=sign(c);
    int diffAB=sa^sb;
    int sameAB=flip(diffAB);
    //增加判断逻辑：ab不同号时，sa要为正，避免c溢出的问题
    int returnA=sa*diffAB+sameAB*sc;
    int returnB=flip(returnA);

    return a*returnA+b*returnB;
}


int main()
{
    int a,b;
    cin>>a>>b;
    int ans1=getMax1(a,b);
    int ans2=getMax2(a,b);

    cout<<ans1<<" "<<ans2<<endl;

    return 0;
}

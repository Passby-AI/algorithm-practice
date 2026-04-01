#include <iostream>
#include <random>
#include <ctime>
#include <unordered_set>

class BitSet
{
public:
    //向上取整 (a+b-1)/b,a,b都为非复数
    BitSet(int n):m((n+31)/32){
         arr=new int[m]{0};
    }
    void add(int num)
    {
        //二进制从右边开始
        //int index=num/32;
        //int p=num%32;
        //int add=1<<p;
        //arr[index]|=add;
        arr[num/32]|=1<<(num%32);
    }
    void remove(int num)
    {
        //用异或的话，0会变为1,但是&上反不会
        /*
        int index=num/32;
        int p=num%32;
        int minus=1<<(32-p);
        */
        arr[num/32]&=~(1<<(num%32));

    }
    void reverse(int num)
    {
        /*
        int index=num/32;
        int p=num%32;
       //提取最右边的1
       int n=arr[index];
       n=n>>p;
       //unsigned int rightOnes=(unsigned int)n&(-(unsigned int) n);
       if((n&1)==1)
           remove(num);
       else
           add(num);
           */
        arr[num/32]^=1<<(num%32);
    };
    bool contains(int num)
    {
       return ((arr[num/32]>>(num%32) ) & 1)==1;
    }
private:
    int m;
    int* arr;
};


//对数测试
int main()
{
    std::default_random_engine e(time(0));
    //测试数据
    int n=1000;
    int testTimes=10000;
    std::cout<<"Test Started\n";
    BitSet bitSet(n);
    //用unordered_set做对照
    std::unordered_set<int> hashSet(n);
    std::cout<<"调用阶段开始\n";
    for(int i=0;i<testTimes;i++)
    {
        std::uniform_int_distribution<int> u(0,n-1);
        int number=u(e);
        std::uniform_real_distribution<double> d(0,1);
        double decide=d(e);
        //number -> 0~n-1
        if(decide<0.333)
        {
            bitSet.add(number);
            hashSet.insert(number);
        }
        else if(decide<0.666)
        {
            bitSet.remove(number);
            hashSet.erase(number);

        }
        else
        {
            bitSet.reverse(number);
            if(hashSet.count(number))
                hashSet.erase(number); 
            else
                hashSet.insert(number);
        }
    }
        std::cout<<"调试阶段结束\n";
        std::cout<<"验证阶段开始\n";
        for(int i=0;i<n;i++)
        {
            if(bitSet.contains(i)!=hashSet.count(i))
                std::cout<<"error\n";
        }
        std::cout<<"验证阶段结束\n";
        std::cout<<"测试结束\n";
        return 0;
    
}

#include <iostream>
#include <utility>
using namespace std;

const int STACKSIZE=100;
template<class T>
class SeqStack
{
    //注意
    //上溢：栈满时入栈
    //下溢：栈空时出栈
    public:
        SeqStack();
        int Empty() { return top==-1? 1:0; }
        T GetTop()  { return top;}
        void Push(T val)
        {
            if(top==STACKSIZE-1)    throw "Out of Index";
            data[++top]=val;
        }
        T Pop()
        {
            if(top==-1) throw "Out of Index";
            T x=data[top--];
            return x;
        }
    private:
        T data[STACKSIZE]; //存储结构
        int top=-1;    //指向顶部的索引
};

//特例：共享栈
template<class T>
class SharedStack
{
    public:
        void Push(T x)
        {
            if(top1==top2-1)    throw"Out of index";
            data[++top1]=x;
            data[--top2]=x;
        }
        pair<T, T> Pop()
        {
            if(top1==-1|| top2 ==STACKSIZE) throw "Out of index";
            T x1=data[top1--];
            T x2=data[top2++];
            return Pair(x1,x2);
        }
    private:
        T data[STACKSIZE];
        int top1=-1;
        int top2=STACKSIZE;

};




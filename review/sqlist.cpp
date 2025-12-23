//线性表实现---顺序表实现
//设计一个通用类，有：数据类型T(template),数据长度L<new delete>,通用操作：插入，删除，查找，输出

template<class T, int N>
class SeqList{

    public:
        SeqList();
        SeqList(T a[],int n);
        int GetLength();
        T Get(int i);
        int Locate(T);
        void Insert(int i, T x);
        T Delete(int i);
        void PrintList();
    private:
        T data[N];
        int length;
};

template<class T,int N>
void SeqList<T,N>::Insert(int i,T x)
{
    if((i<1)||(i>length+1))
        throw "Invalid index";
    if(length>=N)   throw "out of N range";
    for(int j=length;j>=i;j--)
    {
        data[j]=data[j-1];
    }
    data[i-1]=x;
    length++;
}

template<class T, int N>
T SeqList<T,N>::Delete(int i)
{
    if((i<1)||(i>length))   throw "Invalid index";
    if(length==0)   throw "Out of range";
    T t=data[i-1];
    for(int j=i-1;j<length-1;j++)
    {
        data[j]=data[j+1];
    }
    length--;
    return t;
}

template<class T ,int N>
T SeqList<T,N>::Get(int i)
{
    if(i<1||i>length) throw "Invalid index";
    else
        return data[i-1];
}

//按值查找


template<class T,int N>
int SeqList<T,N>::Locate(T x)
{
    for(int i=0;i<length;i++)
    {
        if(data[i]==x)
        {
            return i+1;
        }
    }
    return 0;//如果上面返回下标，这里通常返回-1
}

/*
 * template <class T , int N > int SeqList<T,N>::Locate( T x)
{
int i;
data[0] = x;
for ( i=length; data[i] != x ; i--);
return i;
}
哨兵写法，这种写法通常要求数据必须从下标 1 开始存储，把下标 0 专门空出来当“哨兵”位。
逻辑：把要找的值放在数组头部（下标 0），然后从后往前找。这样循环里就不需要判断 i >= 0（越界检查），因为一定会撞上 data[0] 而停下来。如果最后停在 0，说明没找到（或者就在 0）。
 */


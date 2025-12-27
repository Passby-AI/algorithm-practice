const int QueueSize=100;

template<class T>
class CirQueue
{
    public:
        bool Empty();
        T GetQueue()//获取队头元素
        {
            data[r+1];
        }
        void EnQueue(T val)//进队
        {
            if(f==(r+1)%QueueSize)  throw "Out of Index";
            r=(r+1)%QueueSize;
            data[r]=val;
        }
        T DeQueue()
        {
            if(r==f)    throw "Out of index";//上溢
            f=(f+1)%QueueSize;
            T x=data[f];
            return x;
        }
        int QueueLen()
        {
            return (r-f+QueueSize)%QueueSize;
        }
    private:
        T data[QueueSize];
        int f,r;
};

template<class T>
struct Node
{
    T data;
    Node<T> * next;
};

template<class T>
class LinkQueue
{
    public:
        LinkQueue();
        bool Empty();
        T GetQueue()
        {
            return front->next->data;
        }
        void EnQueue(T x)
        {
            Node<T>*s=new Node<T>;
            s->data=x;
            s->next=nullptr;
            rear->next=s;
            rear=s;
        }
        T DeQueue()
        {
            Node<T>* s=front->next;
            front->next=s->next;
            delete s;
            if(front->next=nullptr) rear=front;
        }
        ~LinkQueue()
        {
            while(front!=nullptr)
            {
                rear=front->next;
                delete front;
                front=rear;
            }
        }
    private:
        Node<T>* front,*rear;


};




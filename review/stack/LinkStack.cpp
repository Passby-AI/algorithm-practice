
template<class T>
struct Node
{
    T data;
    Node<T> *next;
};




template<class T>
class LinkStack
{
    public:
        LinkStack();
        int Empty();
        T GetTop();
        void Push(T x)
        {
            Node<T> *s=new Node<T>;
            s->data=x;
            s->next=top;
            top=s;
        }
        T Pop()
        {
            if(top=nullptr) throw "Out of index";
            Node<T> *p=top;
            T x=p->data;
            top=top->next;
            delete p;
            return x;
        };
        ~LinkStack();
    private:
        Node<T>* top=nullptr;
};

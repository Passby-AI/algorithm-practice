template<class T>
struct Node
{
    T data;
    Node<T> *next;

};


//节点new出来后，使用完毕，必须delete
/*
*生成结点: Node<T> *p=new Node<T>
*为节点赋值:
p->data='a';
p->next=NULL;
* delete p;
* -49-
1 数据类型T（任意）
2 数据长度L（任意）
3 通用操作（算法）：插入 删除 查找 输出
*/

template<class T>
class LinkList
{
    public:
        LinkList();
        LinkList(T a[],int n);
        int Length();
        T Get(int);
        int Locate(T);
        void Insert(T,int);
        T Delete(int);
        ~LinkList();
    private:
        Node<T>*first;

};

template<class T>
LinkList<T>::LinkList()
{
    first=new Node<T>;
    first->next=nullptr;
}

/*
//头插法
template<class T>
LinkList<T>::LinkList(T a[],int n)
{
    first=new Node<T>;
    first->next=nullptr;
    for(int i=0;i<n;i++)
    {
        Node<T> *s=new Node<T>;
        s->data=a[i];
        s->next=first->next;
        first->next=s;
    }
}
*/

//尾插法
template<class T>
LinkList<T>::LinkList(T a[],int n)
{
    Node<T> *first=new Node<T>;
    Node<T> *r=first;
    for(int i=0;i<n;i++)
    {
        Node<T>* s=new Node<T>;
        s->data=a[i];
        s->next=nullptr;
        r->next=s;
        r=s;
    }
}

template<class T>
LinkList<T>::~LinkList()
{
    while(first!=nullptr)
    {
        Node<T> *p=first;
        first=first->next;
        delete p;
    }
}

//按值查找
template<class T>
int LinkList<T>::Locate(T x)
{
    Node<T> *p=first->next;
    int j=1;
    while(p!=nullptr)
    {
        if(first->data==x)
            return j;
        p=p->next;
        j++;
    }
    return 0;
}

template<class T>
T LinkList<T>::Get(int i)
{
    Node<T> *p=first->next;
    int j=1;
    while(j!=i&&p!=nullptr)
    {
        p=p->next;
        j++;
    }
    if(p==nullptr)  throw "Invalid Index";
    return p->data;
}

template<class T>
void LinkList<T>::Insert(T x,int i)
{
    Node<T> *p=first;
    int j=0;
    while(p!=nullptr&&j!=i)
    {
        p->next;
        j++;
    }
    if(p==nullptr)   throw "Invalid index";
    else{
        Node<T>* s=new Node<T>;
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}

template<class T>
T LinkList<T>::Delete(int i)
{
    Node<T> *p=first;
    int j=0;
    while(p->next!=nullptr&&j!=i-1)
    {
        p->next;
        j++;
    }
    if(p->next==nullptr)  throw "Invalid index";
    else
    {
        Node<T>*s=p->next;
        p->next=s->next;
        delete s;
    }
        
}

template<class T>
int LinkList<T>::Length()
{

    Node<T>*p=first;
    int j=0;
    while(p!=nullptr)
    {
        p=p->next;
        j++;
    }
    return j;

}

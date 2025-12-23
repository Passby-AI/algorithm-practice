#include <iostream>
using namespace std;
template<class T>
struct DulNode
{
    T data;
    DulNode<T> *prior,*next;
    DulNode<T>(T val):data(val),prior(nullptr),next(nullptr){}

};

template<class T>
class DoublyLinkList
{
    public:
        DoublyLinkList<T>()
        {
            head=nullptr;
            tail=nullptr;
        }
        ~DoublyLinkList<T>()
        {
            DulNode<T>* current=head;
            while(current!=nullptr)
            {
                DulNode<T> *next=current->next;
                delete current;
                current=next;

            }
        }
        void push_back(T val)
        {
            DulNode<T> * newNode=new DulNode<T>(val);
            if(head==nullptr)
            {
                head=newNode;
                tail=newNode;
            }
            else{
                tail->next=newNode;
                newNode->prior=tail;
                tail=newNode;
            }
        }
        void push_front(T val)
        {
            DulNode<T> *newNode=new DulNode<T>(val);
            if(head==nullptr)
            {
                head=newNode;
                tail=newNode;
            }
            else
            {
                newNode->next=head;
                head->prior=newNode;
                head=newNode;//更新指针
            }

        }
        void Insert(int i,T val)
        {
            if(i<=0)    throw "Invalid Index";
            DulNode<T>* newNode=new DulNode<T>(val);
            DulNode<T>* current=head;
            int j=1;
            while(j!=i&&current!=nullptr)
            {
               current=current->next;
               j++;
            }
            if(current==nullptr)    throw"Invalid Index";
            newNode->next=current;
            newNode->pre=current->pre;
            current->pre=newNode;

        }
        //正向遍历打印
        void printForward()
        {
            DulNode<T>*temp=head;
            while(temp!=nullptr)
            {
                cout<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<"NULL"<<"\n";
        }
        void printBackward()
        {
            DulNode<T>* temp=tail;
            cout<<"NULL"<<" ";
            while(temp!=nullptr)
            {
                cout<<temp->val<<" ";
                temp=temp->prior;
            }
            cout<<"\n";
        }
        
    private:
        DulNode<T>* head;//头指针
        DulNode<T>* tail;//尾指针
};

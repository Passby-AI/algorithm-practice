#include <iostream>
#include <vector>

struct Node
{
    int id;
    Node*next;

    Node(int val):id(val),next(nullptr){}
};


class CircularLinkList
{
    private:
        Node* tail; //这里只保存尾指针，且tail->next 就是head，这样插入更加方便
        int size;   //当前链表元素个数
    public:
        CircularLinkList():tail(nullptr),size(0){}
        ~CircularLinkList()
        {
            if(!tail)   return;
            Node* current=tail->next;
            tail->next=nullptr; //剪开环，避免死循环
            while (current)
            {
                Node *temp=current;
                current=current->next;
                delete temp;
            }
        }
        void add(int id)
        {
            Node* newNode= new Node(id);
            if(tail==nullptr)
            {
                //第一个节点，自己指向自己
                newNode->next=tail->next;
                tail->next=newNode;
                tail=newNode;
            }
            else
            {
                //插入到 tail 后面（即 head 的位置），并更新 tail
                newNode->next=tail->next;
                tail->next=newNode;
                tail=newNode;
            }
            size++;
        }

        //约瑟夫问题
        void run(int m)
        {
            if(size==0) return;
            if(m==1)
            {
                //1,所有人直接出圈
                Node* curr=tail->next;
                while(size>0)
                {
                    std::cout<<curr->id<<" ";
                    Node* temp=curr;
                    curr=curr->next;
                    delete temp;
                    size--;
                }
                std::cout<<std::endl;
                tail->next=nullptr;
                return;
            }
            Node* prev=tail;
            Node* cur=tail->next;

            int count=1;
            std::cout<<"the order of out";
            while(size>0)
            {
                // 报数：移动 m-1 次
                // 目标是让 cur 指向第 m 个人，prev 指向第 m-1 个人
                for(int i=1;i<m;++i)
                {
                    prev=cur;
                    cur=cur->next;
                }
                //说明要出圈的
                std::cout<<cur->id<<" ";
                prev->next=cur->next;
                if(cur==tail)
                {
                    tail=prev;
                }
                delete cur;
                cur=prev->next;
                size--;

            }
            std::cout<<std::endl;
            tail=nullptr;//全部删除后置空


        }

};

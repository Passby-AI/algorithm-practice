#include <iostream>
#include <chrono> //时间库
#include <list>
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
                tail=newNode;
                tail->next=tail;
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
                //新增剪开环，从而避免死循环
                tail->next=nullptr;
                while(size>0)
                {
                    std::cout<<curr->id<<" ";
                    Node* temp=curr;
                    curr=curr->next;
                    delete temp;
                    size--;
                    //如果不剪开环呢？程序可能也不崩溃，虽然最后 curr 指向了一个非法的、已被释放的地址（旧的头节点），但循环恰好在下一轮开始前终止了，我们**没有机会去解引用（访问）**这个非法的 curr
                }
                std::cout<<std::endl;
                tail=nullptr;//直接置空即可，原来指向的内存已经被释放了，里面的成员next之类的可以不用管了
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
//递归公式求解
int josephus_math(int n,int m)
{
    int winner=0;

    for(int i=2;i<=n;++i)
    {
        winner=(winner+m)%i;
    }
    return winner+1;
}
//主程序

int main(){
    int n=100000;
    int m=5000;
    auto start1 = std::chrono::high_resolution_clock::now();
    CircularLinkList circle;
    //初始化
    for(int i =1;i<=n;i++)
    {
        circle.add(i);
    }
//时间测量
    circle.run(m);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time1 = end1 - start1;

    std::cout << "[模拟法] 结果: " 
              << " | 耗时: " << time1.count() << " ms" << std::endl;
    auto start2 = std::chrono::high_resolution_clock::now();
    int result2 = josephus_math(n, m);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> time2 = end2 - start2;

    std::cout << "[数学法] 结果: " << result2 
              << " | 耗时: " << time2.count() << " ms" << std::endl;
    return 0;
}

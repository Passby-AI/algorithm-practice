//测试连接:https://leetcode.cn/problems/design-circular-deque/

//方法一：使用栈实现

struct Linklist
{
    int val;
    Linklist* pre;
    Linklist* next;
    Linklist(int val):val(val),pre(nullptr),next(nullptr){}
};

class MyCircularDeque {
public:
    MyCircularDeque(int k) :limit(k){ 
        
    }
    
    bool insertFront(int value) {
        if(size==limit) return false;
        Linklist* node=new Linklist(value);
        size++;
        if(size==1)
        {
            head=node;
            rear=head;
            return true;
        }
        head->pre=node;
        node->next=head;
        head=node;
        return true;
        

    }
    
    bool insertLast(int value) {
        if(size==limit) return false;
        Linklist* node=new Linklist(value);
        size++;
        if(size==1)
        {
            rear=node;
            head=rear;
  
            return true;
        }
        rear->next=node;
        node->pre=rear;
        rear=node;
        return true;
    }
    
    bool deleteFront() {
        if(size<=0) return false;
        head=head->next;
        if(size!=1)
            head->pre=nullptr;
        size--;
        if(size==0) rear=head;
        return true;
    }
    
    bool deleteLast() {
       if(size<=0)  return false;
       rear=rear->pre;
       if(size!=1)
            head->pre=nullptr;
       size--;
       if(size==0) head=rear;
        return true;
    }
    
    int getFront() {
        if(size<=0) return -1;
        return head->val;
        
    }
    
    int getRear() {
        if(size<=0) return -1;
       return rear->val; 
    }
    
    bool isEmpty() {
        return size==0;
        
    }
    
    bool isFull() {
       return size==limit; 
    }
private:
    int size=0;
    int limit;
    Linklist* head=nullptr;
    Linklist* rear=nullptr;
    
    
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */



        

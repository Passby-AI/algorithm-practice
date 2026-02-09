//方法二：数组实现的循环队列
#define MAXSIZE 10000
class MyCircularDeque {
public:
    MyCircularDeque(int k):limit(k){ 
    }
    
    bool insertFront(int value) {
        if(size==limit) return false;
        head=(head-1+limit)%limit;
        Queue[head]=value;
        size++;
        if(size==1)
            rear=head;
        return true;
    }
    
    bool insertLast(int value) {
       if(size==limit)  return false;
       rear=(rear+1)%limit;
       Queue[rear]=value;
       size++;
       if(size==1)
           head=rear;
       return true;
    }
    
    bool deleteFront() {
       if(size==0) return false;
       head=(head+1)%limit;
       size--;
       if(size==0)
           rear=head;
       return true;
    }
    
    bool deleteLast() {
        
        if(size==0) return false;
        rear=(rear-1+limit)%limit;
        size--;
        if(size==0)
            head=rear;
        return true;
    }
    
    int getFront() {
        if(size>0)
            return Queue[head];
        return -1;
    }
    
    int getRear() {
       if(size>0) 
        return Queue[rear];
       return -1;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==limit;
    }
private:
    int Queue[MAXSIZE];
    int size=0;
    int limit;
    int head=0;
    int rear=0;
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

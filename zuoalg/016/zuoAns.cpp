//方法二：数组实现的循环队列，视频解法
#define MAXSIZE 10000
class MyCircularDeque {
public:
    MyCircularDeque(int k):limit(k),size(0),head(0),rear(0){
        queue=new int[k];
        
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(size==0)
        {
            head=rear=0;
            queue[0]=value;
            size++;
            return true;
        }
        head= (head==0)? limit-1:head-1;
        queue[head]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
       if(isFull())  return false;
       if(size==0)
       {
           head=rear=0;
           queue[0]=value;
           size++;
           return true;
       }
       rear=(rear==limit-1)? 0:rear+1;
       queue[rear]=value;
       size++;
       return true;
    }
    
    bool deleteFront() {
       if(isEmpty()) return false;
       head=head==limit-1? 0:head+1;
       size--;
       return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        rear=rear==0? limit-1:rear-1;
        size--;
        return true;
        
    }
    
    int getFront() {
        if(!isEmpty())
            return queue[head];
        return -1;
    }
    
    int getRear() {
       if(!isEmpty()) 
        return queue[rear];
       return -1;
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return size==limit;
    }
private:
    int *queue;
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


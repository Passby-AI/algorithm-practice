#include <Queue>
#include <Stack>
#include <Queue>

using namespace std;

// 测试链接 : https://leetcode.cn/problems/implement-queue-using-stacks/

class MyQueue {
private:
    stack<int> in;
    stack<int> out;
    void inToOut()
        {
            if(out.empty())
                {
                    while(!in.empty())
                    {
                        //cpp中的pop成员不返回任何值，而java中的返回被弹出的元素
                        out.push(in.top());
                        in.pop();
                    }

                }
        }

    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        in.push(x);
        inToOut();
    }
    
    int pop() {
        inToOut();
        int top=out.top();
        out.pop();
        return top;
    }
    
    int peek() {
        inToOut();
        return out.top();  
    }
    
    bool empty() {
        return in.empty()&& out.empty();
    }
};

class MyStack
{
    queue<int> queue;
    public:
        MyStack();
        void push(int x)
        {
            int n=queue.size();
            int front;
            queue.push(x);
            for(int i=0;i<n;i++)
            {
                front=queue.front();
                queue.pop();
                queue.push(front);
            }
        }
        int pop()
        {
            int front=queue.front();
            queue.pop();
            return front;
        }
        int top()
        {
            return queue.front();
        }
        bool empty()
        {
            return queue.empty();
        }
};

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
class MedianFinder {
public:
    std::priority_queue<int> big;
    std::priority_queue<int,std::vector<int>,std::greater<int>> small;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(big.empty() ||num<=big.top())
            big.push(num);
        else
            small.push(num);
        balance();
    }
    
    double findMedian() {
       if(big.size()==small.size())
           return (double)(big.top()+small.top())/2;
       else
           return big.size()>small.size()? big.top(): small.top();
    }

    void balance()
    {
        if(big.size()-small.size()==2)
        {
           int num=big.top(); 
           big.pop();
            small.push(num);
        }
        if(small.size()-big.size()==2)
        {
            int num=small.top();
            small.pop();
            big.push(num);
        }

    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

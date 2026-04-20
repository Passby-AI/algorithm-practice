#include <unordered_map>
#include <vector>
class FreqStack {
public:
    std::unordered_map<int, int> valueTimes;
    std::unordered_map<int, std::vector<int>> cntValues;
    FreqStack() {
        
    }
    
    void push(int val) {
       if(!valueTimes.count(val))
       {
           valueTimes[val]=1;
           if(cntValues.count(1))
               cntValues[1].push_back(val);
           else
               cntvalues.emplace(1,std::vector<int>{val});
       }
       else
       {
           valueTimes.ad

    }
    
    int pop() {
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

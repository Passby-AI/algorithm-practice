#include <algorithm>
#include <unordered_map>
#include <vector>
class FreqStack {
public:
    std::unordered_map<int, int> valueTimes;
    std::unordered_map<int, std::vector<int>> cntValues;
    int topTimes;
    FreqStack() :topTimes(0){
        
    }
    
    void push(int val) {
       if(!valueTimes.count(val))
       {
           valueTimes[val]=1;
               cntValues[1].push_back(val);
       }
       else
       {
           int times=++valueTimes[val];
            cntValues[times].push_back(val);

       }
       topTimes=std::max(topTimes,valueTimes[val]);
    }
    
    int pop() {
    int e=cntValues[topTimes].back();
     cntValues[topTimes].pop_back();
     valueTimes[e]--;
     if(cntValues[topTimes].empty())
         cntValues.erase(topTimes--);
     if(valueTimes[e]==0)
         valueTimes.erase(e);

     return e;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */

#include <random>
#include <ctime>
#include <unordered_map>
using namespace std;
class RandomizedSet {
private:
    //哈希表记录位置和数字
    unordered_map<int, int> map;
    vector<int> list;
    default_random_engine e;

public:
    RandomizedSet() {
        e.seed(time(0));
    }
    
    bool insert(int val) {
        if(map.count(val))
            return false;
       list.push_back(val);
       map.emplace(val,list.size()-1);
       return true;
    }
    
    bool remove(int val) {
       if(!map.count(val))
           return false;
       int index=map[val];
       int endVal=list.back();
       list[index]=endVal;
       map[endVal]=index;
       list.pop_back();
       map.erase(val);
       return true;
    }
    
    int getRandom() {
       uniform_int_distribution<int> u(0,list.size()-1);
       int index=u(e);
       return list[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


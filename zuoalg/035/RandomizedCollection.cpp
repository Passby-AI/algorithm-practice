#include <random>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class RandomizedCollection {
private:
    unordered_map<int, unordered_set<int>> map;
    vector<int> list;
    default_random_engine e;

public:
    RandomizedCollection() {
        e.seed(time(0));
    }
    
    bool insert(int val) {
        // LeetCode要求：如果之前不存在该元素返回 true，存在返回 false
        bool notPresent = (map.count(val) == 0);
        
        // 直接利用 operator[] 的特性，如果 val 不存在会自动创建一个空的 unordered_set
        map[val].insert(list.size());
        list.push_back(val);
        
        return notPresent;
    }
    
    bool remove(int val) {
        if (!map.count(val) || map[val].empty()) {
            return false;
        }
        
        //获取该值对应的任意一个索引（使用 begin 而不是 end）
        //end()返回的是一个迭代器，指向容器末尾的下一个位置（一个占位符/哨兵），它并不指向任何实际存在的元素。它的底层实现通常是一个空指针
        int removeIndex = *(map[val].begin());
        int lastIndex = list.size() - 1;
        int lastVal = list.back();

        //在数组中，将最后一个元素覆盖到要删除的位置上
        list[removeIndex] = lastVal;

        //更新哈希表（注意顺序，防止 removeIndex 和 lastIndex 相等时出错）
        map[val].erase(removeIndex);       // 删掉要移除的旧索引
        map[lastVal].insert(removeIndex);  // 为最后一个元素添加新索引
        map[lastVal].erase(lastIndex);     // 为最后一个元素删掉旧索引

        //清理空集合
        if (map[val].empty()) {
            map.erase(val);
        }

        //弹出数组最后一个元素
        list.pop_back();

        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<int> u(0, list.size() - 1);
        int index = u(e);
        return list[index];
    }
};

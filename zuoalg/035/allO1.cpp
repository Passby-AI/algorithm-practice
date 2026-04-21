#include <climits>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Bucket {
public:
    unordered_set<std::string> set;
    int cnt;
    Bucket* last;
    Bucket* next;
    
    Bucket(const string s, int cnt) : cnt(cnt), last(nullptr), next(nullptr) {
        if (s != "") {
            set.insert(s);
        }
    }
    
    // 将 pos 插入到 cur 的后面
    void insert(Bucket *cur, Bucket *pos) {
        cur->next->last = pos;
        pos->next = cur->next;
        cur->next = pos;
        pos->last = cur;
    }
    
    // 将 cur 从链表中摘除
    void remove(Bucket *cur) {
        cur->next->last = cur->last;
        cur->last->next = cur->next;
    }
};

class AllOne {
private:
    Bucket* head;
    Bucket* tail;
    unordered_map<string, Bucket*> map;

public:
    AllOne() {
        head = new Bucket("", 0);
        tail = new Bucket("", INT_MAX);
        // 【修复 1】必须连接哨兵节点，形成基础的双向链表
        head->next = tail;
        tail->last = head;
    }
    
    void inc(string key) {
        if (!map.count(key)) {
            // 如果 key 不存在，应该放在 cnt=1 的 Bucket 中（即 head 的后面）
            if (head->next->cnt == 1) {
                head->next->set.insert(key);
                map[key] = head->next;
            } else {
                Bucket* newBucket = new Bucket(key, 1);
                head->insert(head, newBucket);
                map[key] = newBucket;
            }
        } else {
            // key 已经存在
            Bucket* curBucket = map[key];
            Bucket* nextBucket = curBucket->next;
            
            // 1. 将 key 放入下一个频次的 Bucket
            if (nextBucket->cnt == curBucket->cnt + 1) {
                nextBucket->set.insert(key);
                map[key] = nextBucket;
            } else {
                Bucket* newBucket = new Bucket(key, curBucket->cnt + 1);
                curBucket->insert(curBucket, newBucket); // 插入到当前节点之后
                map[key] = newBucket;
            }
            
            // 2. 【修复 2】清理旧的 Bucket
            curBucket->set.erase(key);
            if (curBucket->set.empty()) {
                curBucket->remove(curBucket);
                delete curBucket; // 释放内存
            }
        }
    }
    
    void dec(string key) {
        Bucket* curBucket = map[key];
        
        if (curBucket->cnt == 1) {
            // 如果频次减为 0，直接从哈希表中彻底移除
            map.erase(key);
        } else {
            // 频次大于 1，应该放在 cnt-1 的 Bucket 中（即当前节点的前面）
            Bucket* prevBucket = curBucket->last;
            
            // 1. 将 key 放入前一个频次的 Bucket
            if (prevBucket->cnt == curBucket->cnt - 1) {
                prevBucket->set.insert(key);
                map[key] = prevBucket;
            } else {
                Bucket* newBucket = new Bucket(key, curBucket->cnt - 1);
                // 注意：这里要插入到 prevBucket 的后面，也就是 curBucket 的前面
                prevBucket->insert(prevBucket, newBucket);
                map[key] = newBucket;
            }
        }
        
        // 2. 【修复 2】清理旧的 Bucket
        curBucket->set.erase(key);
        if (curBucket->set.empty()) {
            curBucket->remove(curBucket);
            delete curBucket; // 释放内存
        }
    }
    
    string getMaxKey() {
        if (head->next == tail) return "";
        // 最大值在 tail 的前面
        return *(tail->last->set.begin());
    }
    
    string getMinKey() {
        if (head->next == tail) return "";
        // 最小值在 head 的后面
        return *(head->next->set.begin());
    }
};


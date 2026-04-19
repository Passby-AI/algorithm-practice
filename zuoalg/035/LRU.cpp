#include <unordered_map>

using namespace std;

struct DoubleNode
{
    int key;
    int val;
    DoubleNode* pre;
    DoubleNode* next;
    DoubleNode(int key,int val):key(key),val(val),pre(nullptr),next(nullptr){}
};

class DoubleNodeList
{
    public:
        DoubleNode* head;
        DoubleNode* tail;
        DoubleNodeList():head(nullptr),tail(nullptr){}
        void addNode(DoubleNode* node)
        {
            if(node==NULL)
                return;
            if(head==nullptr)
            {
                head=node;
                tail=node;
            }
            else
            {
                tail->next=node;
                node->pre=tail;
                tail=node;
            }
        }
        void moveNodeToTail(DoubleNode* node)
        {
            if(node==tail)
                return;
            if(head==node)
            {
                head=head->next;
                head->pre=nullptr;
            }
            else{
                node->pre->next=node->next;
                node->next->pre=node->pre;
            }
            node->pre=tail;
            node->next=nullptr;
            tail->next=node;
            tail=node;
        }
        DoubleNode* removeHead()
        {
            DoubleNode* node;
            node=head;
            if(head==tail)
            {
                head=nullptr;
                tail=nullptr;
            }
            else
            {
                head=head->next;
                node->next=nullptr;
                head->pre=nullptr;
            }
            return node;
        }

};
class LRUCache
{
    private:
        unordered_map<int, DoubleNode*> LRUMap;
        int capacity;
        DoubleNodeList nodeList;

    public:
        LRUCache(int capacity):capacity(capacity)
        {}
        int get(int key)
        {
            if(!LRUMap.count(key))
                return -1;
            DoubleNode* ans=LRUMap[key];
            nodeList.moveNodeToTail(ans);
            return ans->val;
        }
        void put(int key,int value)
        {
            if(LRUMap.count(key))
            {
                LRUMap[key]->val=value;
                nodeList.moveNodeToTail(LRUMap[key]);
            }
            else
            {
                if(LRUMap.size()==capacity)
                    LRUMap.erase(nodeList.removeHead()->key);
                DoubleNode* newNode=new DoubleNode(key,value);
                LRUMap.emplace(key,newNode);
                nodeList.addNode(newNode);
            }
        }
};



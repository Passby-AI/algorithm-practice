#include <functional>
#include <queue>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp=[](ListNode* a,ListNode* b)
        {
            return a->val<b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(cmp)> queue(cmp);
        int m=lists.size();
        for(ListNode* h: lists)
        {
            if(h!=nullptr)
                queue.push(h);
        }
        if(queue.empty())
            return nullptr;
        ListNode* head=queue.top();
        queue.pop();
        ListNode* pre=head;
        if(pre->next!=nullptr)
            queue.push(pre->next);
        while(!queue.empty())
        {
            pre->next=queue.top();
            queue.pop();
            pre=pre->next;
            if(pre->next!=nullptr)
                queue.push(pre->next);

        }
        return head;


        
    }
};



int main()
{
    return 0;
}


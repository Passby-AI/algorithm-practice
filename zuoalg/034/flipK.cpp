#include <iostream>
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       //不使用容器的方法
       //第一组要单独处理
       if(head==nullptr||k<=0)
           return head;
       ListNode* end=teamEnd(head,k);
       if(end==nullptr)
           return head;
       ListNode* start=head;
       head=end;
       reverse(start,end);
       ListNode* lastTeamEnd=start;
       while(lastTeamEnd->next!=nullptr)
       {
            start =lastTeamEnd->next;
            end=teamEnd(head,k);
            if(end==nullptr)
            {
                return head;
            }
            reverse(start,end);
            lastTeamEnd->next=end;
            lastTeamEnd=start;

            
       }
       return head;
       
    }
    ListNode* teamEnd(ListNode* start,int k)
    {
        while(--k!=0||start==nullptr)
        {
            start=start->next;
        }
        return start;
        
    }
    void reverse(ListNode* s,ListNode* e)
    {
        e=e->next;
        ListNode* cur=s;
        ListNode* pre=nullptr;
        ListNode* next=cur;
        while(cur!=e)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        s->next=e;

    }
};

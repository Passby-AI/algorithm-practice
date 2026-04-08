#include <iostream>
#include <math.h>


 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       if(headA==nullptr || headB == nullptr)
           return nullptr;
       ListNode* a=headA;
       ListNode* b=headB;

       //diff计算两个链表大小的差值
       int diff = 0;

       while(a!=nullptr)
       {
           a=a->next;
           diff++;
       }

       while(b!=nullptr)
       {
           b=b->next;
           diff--;
       }
       if(a!=b)
           return nullptr;
       if(diff<=0)
       {
           a=headB;
           b=headA;
       }
       if(diff>0)
       {
           a=headA;
           b=headB;
       }
       diff=abs(diff);
       while(diff--!=0)
       {
           a=a->next;
       }
       while(a!=b)
       {
           a=a->next;
           b=b->next;
       }
       return a;

    }
};

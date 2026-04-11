#include <iostream>
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       if(head==NULL || head->next==NULL || head->next->next==NULL)
       {
           return NULL;
       }
       //快慢指针
       ListNode* slow=head->next;
       ListNode* fast=head->next->next;
       while(slow!=fast)
       {
           if(fast->next==NULL || fast->next->next==NULL)
               return NULL;
           slow=slow->next;
           fast=fast->next;
       }
       fast=head;//快指针回到开头
       while(slow!=fast)
       {
           slow=slow->next;
           fast=fast->next;
       }
       return slow;
    }
};

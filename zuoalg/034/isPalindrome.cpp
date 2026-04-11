
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
    bool isPalindrome(ListNode* head) {
       //a->b->c->b->a
       //使用快慢指针
       //用容器：使用栈
       if(head==nullptr) return true;
       ListNode* cur1=head;
       ListNode* cur2=cur1;

       while(cur2!=nullptr && cur2 -> next !=nullptr)
       {
            cur1=cur1->next;
            cur2=cur2->next->next;
       }
       ListNode* pre=cur1;
       ListNode* current=pre->next;
       while(current!=nullptr)
       {
           ListNode* next=current->next;
           current->next=pre;
           pre=current;
           current=next;
       }
       cur1->next=nullptr;
       cur2=head;
       while(cur2==nullptr && pre ==nullptr)
       {
           if(cur2->val!= pre->val)
               return false;
           cur2=cur2->next;
           pre=pre->next;
       }
       return true;


    }
};

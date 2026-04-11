#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) {
      //将复制指针插入，用结构特点代替哈希表的作用
      if(head==NULL)
        return NULL;
      Node* cur=head;
      while(cur!=NULL)
      {
          Node* newNode=new Node(cur->val);
          newNode->next=cur->next;
          cur->next=newNode;
          cur=cur->next->next;//?
      }
      cur=head;
      while(cur!=NULL)
      {
          if(cur->random!=NULL)
          {
              cur->next->random=cur->random->next;
          }
          cur=cur->next->next;
      }

      //剥离出新的节点；
      cur=head;
      Node* ans=head->next;
      while(cur!=NULL)
      {
        Node* next=cur->next->next;
        Node* copy=cur->next;
        cur->next=next;
        copy->next=(next==NULL) ? NULL: next->next;
        cur=cur->next;
      } 
      return ans;
    }
};

